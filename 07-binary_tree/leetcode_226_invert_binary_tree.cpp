/**
 * LeetCode 226. 翻转二叉树
 * https://leetcode.cn/problems/invert-binary-tree/
 *
 * 题目：给你一棵二叉树的根节点 root，翻转这棵二叉树，并返回其根节点。
 *
 * 思路：递归交换左右孩子；或层序遍历逐节点交换
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0226-invert-binary-tree.html
 *
 * 相关题目推荐：
 *   TODO 层序遍历
 *   101. 对称二叉树
 *   100. 相同的树
 */

#include <iostream>
#include "tree_node.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    void doInvertTree(TreeNode *cur) {
        if (!cur) return;
        // 不仅交换每层，下层的孩子也要跟随交换，所以不能仅交换node->val
        swap(cur->left, cur->right);
        doInvertTree(cur->left);
        doInvertTree(cur->right);
    }

    TreeNode *invertTree(TreeNode *root) {
        // 外包，这样root就不用保存，也不用担心返回值，非常方便
        // 当然这里不需要管返回值，swap已经处理当层了，swap的位置决定了前序还是后序，中序不推荐，需要改一出位置，易出错
        doInvertTree(root);
        return root;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [4,2,7,1,3,6,9]
    TreeNode *root1 = createTree({4, 2, 7, 1, 3, 6, 9});
    printTree(solution.invertTree(root1)); // 期望输出 [4,7,2,9,6,3,1]
    deleteTree(root1); // 翻转是就地交换，从原 root 释放即可

    // 示例 2：树 [2,1,3]
    TreeNode *root2 = createTree({2, 1, 3});
    printTree(solution.invertTree(root2)); // 期望输出 [2,3,1]
    deleteTree(root2);

    return 0;
}
