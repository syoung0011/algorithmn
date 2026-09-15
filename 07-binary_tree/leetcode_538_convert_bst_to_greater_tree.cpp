/**
 * LeetCode 538. 把二叉搜索树转换为累加树
 * https://leetcode.cn/problems/convert-bst-to-greater-tree/
 *
 * 题目：给出二叉搜索树的根节点，该树的节点值各不相同，请你将其转换为累加树，
 *       使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
 *
 * 思路：反中序遍历（右-中-左），累加前缀和更新节点值
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0538-convert-bst-to-greater-tree.html
 *
 * 相关题目推荐：
 *   1038. 从二叉搜索树到更大和树
 *   530. 二叉搜索树的最小绝对差
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

int pre = 0;

class Solution {
public:
    void traversal(TreeNode *cur) {
        if (!cur) return;
        // 不用返回值，因为方向不同，而且返回逻辑不唯一，比较复杂，那就直接新建变量，不要一条路走到黑
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }

    TreeNode *convertBST(TreeNode *root) {
        pre = 0;
        traversal(root);
        return root;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    TreeNode *root1 = createTree({4, 1, 6, 0, 2, 5, 7, INT_MIN, INT_MIN, INT_MIN, 3, INT_MIN, INT_MIN, INT_MIN, 8});
    printTree(solution.convertBST(root1)); // 期望输出 [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
    deleteTree(root1); // 转换是就地修改节点值，从原 root 释放即可

    // 示例 2：树 [0,null,1]
    TreeNode *root2 = createTree({0, INT_MIN, 1});
    printTree(solution.convertBST(root2)); // 期望输出 [1,null,1]
    deleteTree(root2);

    return 0;
}
