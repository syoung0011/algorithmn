/**
 * LeetCode 107. 二叉树的层序遍历 II
 * https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
 *
 * 题目：给你二叉树的根节点 root，返回其节点值自底向上的层序遍历。
 *       （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）。
 *
 * 思路：先做自顶向下的层序遍历，最后将结果整体反转
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(w)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0102-binary-tree-level-order-traversal.html
 *
 * 相关题目推荐：
 *   102. 二叉树的层序遍历
 *   199. 二叉树的右视图
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if (!root) return {};
        queue<TreeNode *> que;
        vector<vector<int> > res;
        vector<int> level_vec;
        int cnt = 1;
        que.push(root);
        while (!que.empty()) {
            TreeNode *front = que.front(); // 命名最好用cur
            que.pop();
            level_vec.push_back(front->val);
            if (front->left) {
                que.push(front->left);
            }
            if (front->right) {
                que.push(front->right);
            }
            if (--cnt == 0) {
                res.push_back(level_vec);
                level_vec.clear();
                cnt = que.size();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [3,9,20,null,null,15,7]
    TreeNode *root1 = createTree({3, 9, 20, INT_MIN, INT_MIN, 15, 7});
    for (const auto &level: solution.levelOrderBottom(root1)) {
        for (int num: level) {
            cout << num << " "; // 期望输出 15 7 / 9 20 / 3
        }
        cout << endl;
    }
    deleteTree(root1);

    // 示例 2：树 [1]
    TreeNode *root2 = createTree({1});
    for (const auto &level: solution.levelOrderBottom(root2)) {
        for (int num: level) {
            cout << num << " "; // 期望输出 1
        }
        cout << endl;
    }
    deleteTree(root2);

    return 0;
}
