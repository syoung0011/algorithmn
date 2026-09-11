/**
 * LeetCode 530. 二叉搜索树的最小绝对差
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
 *
 * 题目：给你一个二叉搜索树的根节点 root，返回树中任意两不同节点值之间的最小
 *       差值（绝对值）。差值是一个正数，其数值等于两值之差的绝对值。
 *
 * 思路：中序遍历得到递增序列，相邻元素差值取最小；或递归中记录前驱节点
 *
 * 复杂度：时间复杂度 O(n * h)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0530-minimum-absolute-difference-in-bst.html
 *
 * 相关题目推荐：
 *   501. 二叉搜索树中的众数
 *   98. 验证二叉搜索树
 *   783. 二叉搜索树节点最小距离
 */

#include <iostream>
#include "tree_node.h"
#include <algorithm>   // std::min
#include <climits>     // INT_MAX / INT_MIN（当前靠 tree_node.h 传递，应自给自足）

using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode *root) {
        // 错误做法，只判断直接相连的父子，却忽略了BST真正的前驱后继
        // int left = INT_MAX, right = INT_MAX;
        // int leftDiff = INT_MAX, rightDiff = INT_MAX;
        // if (root->left) {
        //     left = getMinimumDifference(root->left);
        //     leftDiff = root->val - root->left->val;
        // }
        // if (root->right) {
        //     right = getMinimumDifference(root->right);
        //     rightDiff = root->right->val - root->val;
        // }
        // return min(min(left, right), min(leftDiff, rightDiff));

        // 正确做法，对比每个节点的前驱后继，但其实中序遍历放到数组里面再逐对比较最简便
        // 或者用pre记录前驱，往左遍历的时候是不用更新pre的，他不是父亲而是BST的前驱，这一点要注意
        int leftDiff = INT_MAX, rightDiff = INT_MAX;
        int left = INT_MAX, right = INT_MAX;
        // 题目条件，根不可能空，所以不需判空
        if (root->left) {
            TreeNode *cur = root->left;
            while (cur->right) {
                cur = cur->right;
            }
            leftDiff = root->val - cur->val;
            left = getMinimumDifference(root->left);
        }
        if (root->right) {
            TreeNode *cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            rightDiff = cur->val - root->val;
            right = getMinimumDifference(root->right);
        }
        return min(min(left, right), min(leftDiff, rightDiff));
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [4,2,6,1,3]
    TreeNode *root1 = createTree({4, 2, 6, 1, 3});
    cout << solution.getMinimumDifference(root1) << endl; // 期望输出 1
    deleteTree(root1);

    // 示例 2：树 [1,0,48,null,null,12,49]
    TreeNode *root2 = createTree({1, 0, 48, INT_MIN, INT_MIN, 12, 49});
    cout << solution.getMinimumDifference(root2) << endl; // 期望输出 1
    deleteTree(root2);

    return 0;
}
