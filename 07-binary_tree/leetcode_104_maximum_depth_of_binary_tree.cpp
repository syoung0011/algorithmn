/**
 * LeetCode 104. 二叉树的最大深度
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/
 *
 * 题目：给定一个二叉树 root，返回其最大深度。二叉树的深度为根节点到最远叶子
 *       节点的最长路径上的节点数。
 *
 * 思路：递归，max(左子树深度, 右子树深度) + 1 或 层序遍历统计层数
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0104-maximum-depth-of-binary-tree.html
 *
 * 相关题目推荐：
 *   TODO 前序和迭代法
 *   111. 二叉树的最小深度
 *   559. N 叉树的最大深度
 *   110. 平衡二叉树
 */

#include <algorithm>   // std::max
#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    // 本质后序，根节点的高度代表树的深度
    int getMaxDepth(TreeNode *cur) {
        if (!cur) return 0;
        // 分清逻辑，+1是本层高度，因为本层不空，不要交给下一层。max判断最深
        return max(getMaxDepth(cur->left), getMaxDepth(cur->right)) + 1;
    }

    int maxDepth(TreeNode *root) {
        return getMaxDepth(root); // 外包
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [3,9,20,null,null,15,7]
    TreeNode *root1 = createTree({3, 9, 20, INT_MIN, INT_MIN, 15, 7});
    cout << solution.maxDepth(root1) << endl; // 期望输出 3
    deleteTree(root1);

    // 示例 2：树 [1,null,2]
    TreeNode *root2 = createTree({1, INT_MIN, 2});
    cout << solution.maxDepth(root2) << endl; // 期望输出 2
    deleteTree(root2);

    return 0;
}
