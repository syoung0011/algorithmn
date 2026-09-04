/**
 * LeetCode 515. 在每个树行中找最大值
 * https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
 *
 * 题目：给定一棵二叉树的根节点 root，请找出该二叉树中每一层的最大值。
 *
 * 思路：层序遍历，每层记录最大值
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(w)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0102-binary-tree-level-order-traversal.html
 *
 * 相关题目推荐：
 *   102. 二叉树的层序遍历
 *   637. 二叉树的层平均值
 */

#include <iostream>
#include <vector>
#include "tree_node.h"
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        queue<TreeNode *> que;
        if (root) que.push(root);
        vector<int> res;
        while (!que.empty()) {
            int cnt = que.size();
            int cur_max = INT_MIN;
            while (cnt--) {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->val > cur_max) cur_max = cur->val; // 直接调用max更好
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            res.push_back(cur_max);
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,3,2,5,3,null,9]
    TreeNode *root1 = createTree({1, 3, 2, 5, 3, INT_MIN, 9});
    for (int num: solution.largestValues(root1)) {
        cout << num << " "; // 期望输出 1 3 9
    }
    cout << endl;
    deleteTree(root1);

    // 示例 2：树 [1,2,3]
    TreeNode *root2 = createTree({1, 2, 3});
    for (int num: solution.largestValues(root2)) {
        cout << num << " "; // 期望输出 1 3
    }
    cout << endl;
    deleteTree(root2);

    return 0;
}
