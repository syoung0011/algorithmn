/**
 * LeetCode 404. 左叶子之和
 * https://leetcode.cn/problems/sum-of-left-leaves/
 *
 * 题目：给定二叉树的根节点 root，返回所有左叶子之和。左叶子是指：节点 A 的
 *       左孩子节点为叶子节点（没有左右孩子），则该左孩子就是左叶子。
 *
 * 思路：递归，判断当前节点左孩子是否为叶子，是则累加，再分别递归左右子树
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0404-sum-of-left-leaves.html
 *
 * 相关题目推荐：
 *   TODO 长指针判断，cur->left->left也是可行的，见官网
 *   257. 二叉树的所有路径
 *   112. 路径总和
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    int getLeftSum(TreeNode *cur, bool isLeft) {
        if (!cur) return 0;
        if (!cur->left && !cur->right && isLeft) return cur->val;
        return getLeftSum(cur->left, true) + getLeftSum(cur->right, false);
    }

    int sumOfLeftLeaves(TreeNode *root) {
        // 初始false，因为单独根节点是叶子，但不算作左叶子，左叶子要求一定有父，被其父的左指针绑定
        return getLeftSum(root, false);
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [3,9,20,null,null,15,7]
    TreeNode *root1 = createTree({3, 9, 20, INT_MIN, INT_MIN, 15, 7});
    cout << solution.sumOfLeftLeaves(root1) << endl; // 期望输出 24（9 + 15）
    deleteTree(root1);

    // 示例 2：树 [1]
    TreeNode *root2 = createTree({1});
    cout << solution.sumOfLeftLeaves(root2) << endl; // 期望输出 0
    deleteTree(root2);

    return 0;
}
