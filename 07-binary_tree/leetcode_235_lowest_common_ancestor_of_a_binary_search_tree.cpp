/**
 * LeetCode 235. 二叉搜索树的最近公共祖先
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
 *
 * 题目：给定一个二叉搜索树，找到该树中两个指定节点的最近公共祖先。利用 BST
 *       性质：p、q 的值都小于当前节点则往左找，都大于则往右找，否则当前节点
 *       就是分岔点即最近公共祖先。
 *
 * 思路：利用 BST 有序性迭代或递归，避免遍历整棵树
 *
 * 复杂度：时间复杂度 O(h)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0235-lowest-common-ancestor-of-a-binary-search-tree.html
 *
 * 相关题目推荐：
 *   236. 二叉树的最近公共祖先
 *   700. 二叉搜索树中的搜索
 */

#include <iostream>
#include "tree_node.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    // 也可用迭代法，空间更优
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // 用min/max更简洁
        if (root->val < min(p->val, q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [6,2,8,0,4,7,9,null,null,3,5]，p=2, q=8
    TreeNode *root1 = createTree({6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5});
    TreeNode *p1 = root1->left; // 值为 2
    TreeNode *q1 = root1->right; // 值为 8
    cout << solution.lowestCommonAncestor(root1, p1, q1)->val << endl; // 期望输出 6

    // 示例 2：p=2, q=4（2 是 4 的祖先）
    TreeNode *p2 = root1->left; // 值为 2
    TreeNode *q2 = root1->left->right; // 值为 4
    cout << solution.lowestCommonAncestor(root1, p2, q2)->val << endl; // 期望输出 2
    deleteTree(root1); // 两个示例共用同一棵树，最后统一释放

    return 0;
}
