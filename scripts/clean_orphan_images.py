# 扫描仓库中 *.assets 目录下的图片：
#   1. 找出内容完全相同的重复图片（按 SHA1）
#   2. 找出未被任何 .md 引用的孤儿图片
#
# 用法：
#   python scripts/clean_orphan_images.py           # 仅报告，不删除
#   python scripts/clean_orphan_images.py --delete  # 删除"孤儿图"（重复组中未被引用的副本）
#
# 注意：两处都引用的重复图不会自动删除（需要人工确认保留哪张并改 md 引用）

import hashlib
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP_DIRS = {".git", "build", "build-mingw-test", "cmake-build-debug", ".idea"}
IMG_EXTS = {".png", ".jpg", ".jpeg", ".gif", ".webp", ".svg", ".bmp"}

md_re = re.compile(r"!\[[^\]]*\]\(([^)]+)\)")


def main():
    do_delete = "--delete" in sys.argv

    images = {}  # abs path -> sha1
    for dirpath, dirnames, filenames in os.walk(ROOT):
        dirnames[:] = [d for d in dirnames if d not in SKIP_DIRS]
        if dirpath.endswith(".assets"):
            for fn in filenames:
                if os.path.splitext(fn)[1].lower() in IMG_EXTS:
                    p = os.path.join(dirpath, fn)
                    with open(p, "rb") as f:
                        images[p] = hashlib.sha1(f.read()).hexdigest()

    referenced = set()
    for dirpath, dirnames, filenames in os.walk(ROOT):
        dirnames[:] = [d for d in dirnames if d not in SKIP_DIRS]
        for fn in filenames:
            if fn.lower().endswith(".md"):
                with open(os.path.join(dirpath, fn), encoding="utf-8") as f:
                    content = f.read()
                for m in md_re.finditer(content):
                    ref = m.group(1).strip().strip("<>")
                    if ref.startswith("http"):
                        continue
                    referenced.add(os.path.normpath(os.path.join(dirpath, ref)))

    by_hash = {}
    for p, h in images.items():
        by_hash.setdefault(h, []).append(p)

    to_delete = []
    print("total images: %d, referenced: %d" % (len(images), len(referenced)))

    print("\n--- duplicate groups (same content) ---")
    for h, paths in by_hash.items():
        if len(paths) > 1:
            print("hash %s:" % h[:10])
            for p in sorted(paths):
                used = p in referenced
                print("  [%s] %s" % ("REF" if used else "unused", os.path.relpath(p, ROOT)))
                if not used:
                    to_delete.append(p)
            if all(p in referenced for p in paths):
                print("  ^ all referenced, keep as-is; fix md refs manually if needed")

    print("\n--- unreferenced (orphan) files ---")
    for p in sorted(images):
        if p not in referenced:
            print("  %s" % os.path.relpath(p, ROOT))
            if p not in to_delete:
                to_delete.append(p)

    if do_delete and to_delete:
        for p in to_delete:
            os.remove(p)
            print("deleted: %s" % os.path.relpath(p, ROOT))
    elif to_delete:
        print("\n%d file(s) can be deleted, rerun with --delete to remove" % len(to_delete))


if __name__ == "__main__":
    main()
