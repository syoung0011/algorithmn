/**
 * LeetCode 112. 路径总和
 * https://leetcode.cn/problems/path-sum/
 *
 * 题目：给你二叉树的根节点 root 和一个表示目标和的整数 targetSum，判断该树中
 *       是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和
 *       targetSum。如果存在，返回 true；否则返回 false。
 *
 * 思路：递归，目标值逐层递减，叶子节点判断是否归零
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0112-path-sum.html
 *
 * 相关题目推荐：
 *   113. 路径总和 II
 *   257. 二叉树的所有路径
 *   437. 路径总和 III
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

// 累加需要额外变量，要么传参要么全局
// 但累减则复用targetSum参数即可，最为简洁
int curSum = 0;

class Solution {
public:
    bool getPathSum(TreeNode *cur, int targetSum) {
        if (!cur) return false;
        curSum += cur->val;
        // 因为不需要路径，只需要判断，所以就不回溯curSum了，正规还是要回溯的
        if (curSum == targetSum && !cur->left && !cur->right) return true;
        bool ret = getPathSum(cur->left, targetSum) || getPathSum(cur->right, targetSum);
        curSum -= cur->val;
        return ret;
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        curSum = 0;
        return getPathSum(root, targetSum);
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [5,4,8,11,null,13,4,7,2,null,null,null,1]
    TreeNode *root1 = createTree({5, 4, 8, 11, INT_MIN, 13, 4, 7, 2, INT_MIN, INT_MIN, INT_MIN, 1});
    cout << (solution.hasPathSum(root1, 22) ? "true" : "false") << endl; // 期望输出 true
    deleteTree(root1);

    // 示例 2：树 [1,2,3]
    TreeNode *root2 = createTree({1, 2, 3});
    cout << (solution.hasPathSum(root2, 5) ? "true" : "false") << endl; // 期望输出 false
    deleteTree(root2);

    // 示例 3：空树
    cout << (solution.hasPathSum(nullptr, 0) ? "true" : "false") << endl; // 期望输出 false

    return 0;
}
