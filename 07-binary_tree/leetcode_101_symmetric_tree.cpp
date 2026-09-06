/**
 * LeetCode 101. 对称二叉树
 * https://leetcode.cn/problems/symmetric-tree/
 *
 * 题目：给你一个二叉树的根节点 root，检查它是否轴对称。
 *
 * 思路：递归比较 左.左 vs 右.右 和 左.右 vs 右.左
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0101-symmetric-tree.html
 *
 * 相关题目推荐：
 *   TODO 迭代：层序遍历每层检查是否回文或栈
 *   100. 相同的树
 *   226. 翻转二叉树
 *   572. 另一棵树的子树
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    bool compare(TreeNode *left, TreeNode *right) {
        // 整个算法可视为后序，左右根，即只有检查完A的孩子是否合法，才能知道A本身是否合法
        // 但内部判断逻辑不太好理解为后续，因为两个节点，但其实本质也是后序，if就类似访问
        if (!left && right) return false; // 没必要验证子树了直接返回
        if (left && !right) return false;
        if (!left && !right) return true;
        if (left->val != right->val) return false; // 这里最好反面，不等直接返回
        // 类似左右指针同步向内收缩
        return compare(left->left, right->right) && compare(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return compare(root->left, root->right);
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,2,2,3,4,4,3]
    TreeNode *root1 = createTree({1, 2, 2, 3, 4, 4, 3});
    cout << (solution.isSymmetric(root1) ? "true" : "false") << endl; // 期望输出 true
    deleteTree(root1);

    // 示例 2：树 [1,2,2,null,3,null,3]
    TreeNode *root2 = createTree({1, 2, 2, INT_MIN, 3, INT_MIN, 3});
    cout << (solution.isSymmetric(root2) ? "true" : "false") << endl; // 期望输出 false
    deleteTree(root2);

    return 0;
}
