# algorithmn

代码随想录刷题记录（C++11）

跟着 [代码随想录](https://programmercarl.com/) 刷题，每题一个独立可编译的 C++ 源文件，按专题分目录存放，通过 Git 同步到 GitHub，记录完整的学习轨迹。

## 目录结构

```
algorithmn/
├── include/                    # 公共工具头文件
│   ├── list_node.h             # 链表节点定义 + 创建/打印/释放工具
│   └── tree_node.h             # 二叉树节点定义 + 构造/打印/释放工具
├── 01-array/
├── 02-linked_list/
├── 03-hash_table/
├── 04-string/
├── 05-two_pointers/
├── 06-stack_and_queue/
├── 07-binary_tree/
├── 08-backtracking/
├── 09-greedy/
├── 10-dynamic_programming/
├── 11-monotonic_stack/
├── 12-graph_theory/
├── 13-other_classic/
├── NOTES.md                    # 通用笔记：C++ 前置、工具链、跨专题积累
└── CMakeLists.txt              # 自动收集所有题解，每题一个可执行文件
```

## 如何新增一题

1. 在对应专题目录新建文件，命名格式：`leetcode_题号_题目英文名.cpp`，如 `leetcode_704_binary_search.cpp`；英文名想不起来时可以省略，只写题号：`leetcode_344.cpp`（文件名请用 ASCII 字符，中文文件名会导致 CMake 配置失败）
2. 文件头部注释写明：题目链接、解题思路、复杂度分析（参照 `01-array/leetcode_704_binary_search.cpp` 的模板）
3. 链表/二叉树题目可 `#include "list_node.h"` / `#include "tree_node.h"` 复用公共定义，不用重复写节点结构
4. 每题自带 `main()` 和测试用例，确保本地可独立运行
5. 新增文件后，在 CLion 中点击 "Reload CMake Project"，即可单独运行该题
6. 命令行编译单个题目（假设已配置好构建目录）：

   ```bash
   cmake --build build --target leetcode_704_binary_search
   ```

## 提交规范

- 一道题一次 commit，message 格式：`[专题] LeetCode 题号. 题目名`
- 示例：`[数组] LeetCode 704. 二分查找`
- 笔记随手记随手提交，各专题心得写入对应目录的 `NOTES.md`，跨专题内容写入根目录 `NOTES.md`：
  - 日常记录：`[专题] notes: 简要说明`，如 `[链表] notes: 插入删除用 cur cur->next`
  - 通用笔记：`[notes] 简要说明`
  - 专题收尾整理：`[专题] notes: 专题整理`
- 修改已有题解（发现错误、事后优化）单独成 commit，不混入新题提交：`[专题] fix: 简要说明`
- 每周总结：每周一回顾上一周，Wxx 填**被总结**的那一周；内容简短直接写 commit message，篇幅较长则追加到根目录 `NOTES.md`
  - 格式：`[weekly] 2026-Wxx summary: 简要说明`
  - 示例：`[weekly] 2026-W33 summary: progress & reflections`（周一提交，总结 W33）
- 构建产物目录（如 `cmake-build-debug/`）已被 .gitignore 忽略，不会上传

## 打卡进度

| 专题 | 目录 | 题数 | 进度   |
| ---- | ---- | ---- |------|
| 数组 | 01-array | 7 | 7/7  |
| 链表 | 02-linked_list | 7 | 6/7  |
| 哈希表 | 03-hash_table | 8 | 0/8  |
| 字符串 | 04-string | 7 | 0/7  |
| 双指针法 | 05-two_pointers | 0 | 0/0  |
| 栈与队列 | 06-stack_and_queue | 7 | 0/7  |
| 二叉树 | 07-binary_tree | 39 | 0/39 |
| 回溯算法 | 08-backtracking | 15 | 0/15 |
| 贪心算法 | 09-greedy | 17 | 0/17 |
| 动态规划 | 10-dynamic_programming | 35 | 0/35 |
| 单调栈 | 11-monotonic_stack | 5 | 0/5  |
| 图论 | 12-graph_theory | 21 | 0/21 |
| 其他经典题目 | 13-other_classic | 0 | 0/0  |

当前共计 **168** 题。

- 进度格式为 `x/y`：y 为该专题题数（按目录下的题解 `.cpp` 文件数统计），新增题目后请同步更新"题数"与 y
- 刷完一题后，自行把 x 更新为实际完成的题数；x 达到 y 即该专题已完成
