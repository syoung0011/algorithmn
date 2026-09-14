/**
 * LeetCode 669. 修剪二叉搜索树
 * https://leetcode.cn/problems/trim-a-binary-search-tree/
 *
 * 题目：给你二叉搜索树的根节点 root，同时给定最小边界 low 和最大边界 high。
 *       通过修剪二叉搜索树，使得所有节点的值在 [low, high] 中。修剪树不应该
 *       改变保留在树中的节点的相对结构。返回修剪好的二叉搜索树的唯一的根节点。
 *
 * 思路：递归，节点值小于 low 则修剪左子树后返回右子树，大于 high 则修剪右子树后返回左子树
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0669-trim-a-binary-search-tree.html
 *
 * 相关题目推荐：
 *   TODO 迭代法
 *   450. 删除二叉搜索树中的节点
 *   701. 二叉搜索树中的插入操作
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    // 不要被题目保留结构吓到，很多力扣题目的条件只是在给你线索，而不是在为难你
    // 单侧越界时只有一侧可能含合法节点，所以左右二选一往下走，不用像删除BST那样重建结构
    // 注意：返回新子树前，必须释放被剪掉的节点，否则父节点指针被覆盖后这些节点再也无法访问
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (!root) return root;
        // 二选一：当前节点及其左子树全部越界，右子树中可能仍有合法节点
        if (root->val < low) {
            TreeNode *right = trimBST(root->right, low, high);
            // 算法题可不在意内存释放，本题的释放还多一步后序删除
            deleteTree(root->left); // 左子树全部越界，整体释放
            delete root;
            return right;
        }
        // 对称：当前节点及其右子树全部越界
        if (root->val > high) {
            TreeNode *left = trimBST(root->left, low, high);
            deleteTree(root->right); // 右子树全部越界，整体释放
            delete root;
            return left;
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,0,2]，low=1, high=2
    TreeNode *root1 = createTree({1, 0, 2});
    TreeNode *trimmed1 = solution.trimBST(root1, 1, 2);
    printTree(trimmed1); // 期望输出 [1,null,2]
    // 越界节点已由 trimBST 内部释放，这里只释放修剪后的树
    // 注意：不能再用 root1 释放（其 left 已被覆盖，且旧节点已 delete）
    deleteTree(trimmed1);

    // 示例 2：树 [3,0,4,null,2,null,null,1]，low=1, high=3
    TreeNode *root2 = createTree({3, 0, 4, INT_MIN, 2, INT_MIN, INT_MIN, 1});
    TreeNode *trimmed2 = solution.trimBST(root2, 1, 3);
    printTree(trimmed2); // 期望输出 [3,2,null,1]
    deleteTree(trimmed2);

    return 0;
}
