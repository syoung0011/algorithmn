/**
 * LeetCode 700. 二叉搜索树中的搜索
 * https://leetcode.cn/problems/search-in-a-binary-search-tree/
 *
 * 题目：给定二叉搜索树（BST）的根节点 root 和一个整数值 val，在 BST 中找到
 *       节点值等于 val 的节点，并返回以该节点为根的子树。如果节点不存在，则
 *       返回 null。
 *
 * 思路：利用 BST 有序性，val 小于当前值向左搜，大于向右搜
 *
 * 复杂度：时间复杂度 O(h)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0700-search-in-a-binary-search-tree.html
 *
 * 相关题目推荐：
 *   98. 验证二叉搜索树
 *   701. 二叉搜索树中的插入操作
 *   450. 删除二叉搜索树中的节点
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    // 递归法，BST搜索迭代法更好，空间更优
    TreeNode* searchBST(TreeNode* root, int val) {
        // 这里可以写的更完美，合并相等的情形直接return root
        if (!root) return nullptr;
        if (root->val < val) {
            return searchBST(root->right, val);
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        return root;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [4,2,7,1,3]
    TreeNode* root1 = createTree({4, 2, 7, 1, 3});
    printTree(solution.searchBST(root1, 2));  // 期望输出 [2,1,3]

    // 示例 2
    printTree(solution.searchBST(root1, 5));  // 期望输出 null
    deleteTree(root1);  // 两个示例共用同一棵树，最后统一释放

    return 0;
}
