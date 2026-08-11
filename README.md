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
- 构建产物目录（如 `cmake-build-debug/`）已被 .gitignore 忽略，不会上传

## 打卡进度

| 专题 | 目录 | 状态 |
| ---- | ---- | ---- |
| 数组 | 01-array | 未开始 |
| 链表 | 02-linked_list | 未开始 |
| 哈希表 | 03-hash_table | 未开始 |
| 字符串 | 04-string | 未开始 |
| 双指针法 | 05-two_pointers | 未开始 |
| 栈与队列 | 06-stack_and_queue | 未开始 |
| 二叉树 | 07-binary_tree | 未开始 |
| 回溯算法 | 08-backtracking | 未开始 |
| 贪心算法 | 09-greedy | 未开始 |
| 动态规划 | 10-dynamic_programming | 未开始 |
| 单调栈 | 11-monotonic_stack | 未开始 |
| 图论 | 12-graph_theory | 未开始 |
| 其他经典题目 | 13-other_classic | 未开始 |

刷完一题后，把对应专题的状态改为 `进行中`；整个专题完成改为 `已完成`。
