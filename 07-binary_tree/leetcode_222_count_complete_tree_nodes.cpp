/**
 * LeetCode 222. 完全二叉树的节点个数
 * https://leetcode.cn/problems/count-complete-tree-nodes/
 *
 * 题目：给你一棵完全二叉树的根节点 root，求出该树的节点个数。
 *
 * 思路：利用完全二叉树性质，左右子树深度相同则用公式
 *       2^depth - 1，否则递归；或简单递归遍历计数
 *
 * 复杂度：时间 O(log^2 n)（每层沿链探测树高 O(log n)，共递归 O(log n) 层），空间 O(log n)（递归栈深度即树高）
 *        朴素遍历版 getCountRecur 为 时间 O(n) / 空间 O(log n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0222-count-complete-tree-nodes.html
 *
 * 相关题目推荐：
 *   104. 二叉树的最大深度
 *   110. 平衡二叉树
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    int getCountRecur(TreeNode *cur) {
        if (!cur) return 0;
        return countNodes(cur->left) + countNodes(cur->right) + 1;
    }

    int getCount(TreeNode *cur) {
        if (!cur) return 0;
        TreeNode *left = cur->left;
        TreeNode *right = cur->right;
        // 不要初始化为1，不然while(left->left)，指针为空，报错
        // 可以用退化来记忆，这就像链表，while循环不变式用cur->next还是cur呢，不同题要有不同考虑
        int leftHeight = 0;
        int rightHeight = 0;
        while (left) {
            left = left->left;
            leftHeight++;
        }
        while (right) {
            right = right->right;
            rightHeight++;
        }
        if (leftHeight == rightHeight) return (2 << leftHeight) - 1;
        // 不能用left, right变量，已经改变了
        return getCount(cur->left) + getCount(cur->right) + 1;
    }

    int countNodes(TreeNode *root) {
        // 递归方法无法通过OJ
        // return getCountRecur(root);

        // 不用getCount(root->left) + getCount(cur->right) + 1
        // 但印象里确实有的题要这么干，取决于循环中，树高度的计算逻辑，是否包括当前层
        return getCount(root);
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,2,3,4,5,6]
    TreeNode *root1 = createTree({1, 2, 3, 4, 5, 6});
    cout << solution.countNodes(root1) << endl; // 期望输出 6
    deleteTree(root1);

    // 示例 2：空树
    cout << solution.countNodes(nullptr) << endl; // 期望输出 0

    // 示例 3：树 [1]
    TreeNode *root3 = createTree({1});
    cout << solution.countNodes(root3) << endl; // 期望输出 1
    deleteTree(root3);

    return 0;
}
