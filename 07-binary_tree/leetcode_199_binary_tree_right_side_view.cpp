/**
 * LeetCode 199. 二叉树的右视图
 * https://leetcode.cn/problems/binary-tree-right-side-view/
 *
 * 题目：给定一个二叉树的根节点 root，想象自己站在它的右侧，按照从顶部到底部的
 *       顺序，返回从右侧所能看到的节点值。
 *
 * 思路：层序遍历，每层取最后一个节点；或 DFS 先右后左
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(w)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0102-binary-tree-level-order-traversal.html
 *
 * 相关题目推荐：
 *   102. 二叉树的层序遍历
 *   515. 在每个树行中找最大值
 */

#include <iostream>
#include <vector>
#include "tree_node.h"
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root) return {};
        vector<int> res;
        vector<vector<int> > vec;
        vector<int> level_vec;
        queue<TreeNode *> que;
        que.push(root);
        int cnt = 1;
        while (!que.empty()) {
            TreeNode *cur = que.front();
            que.pop();
            level_vec.push_back(cur->val);
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
            if (--cnt == 0) {
                vec.push_back(level_vec);
                level_vec.clear();
                cnt = que.size();
            }
        }
        for (auto entry: vec) {
            res.push_back(entry.back()); // 也可对end-1解引用
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,2,3,null,5,null,4]
    TreeNode *root1 = createTree({1, 2, 3, INT_MIN, 5, INT_MIN, 4});
    for (int num: solution.rightSideView(root1)) {
        cout << num << " "; // 期望输出 1 3 4
    }
    cout << endl;
    deleteTree(root1);

    // 示例 2：树 [1,null,3]
    TreeNode *root2 = createTree({1, INT_MIN, 3});
    for (int num: solution.rightSideView(root2)) {
        cout << num << " "; // 期望输出 1 3
    }
    cout << endl;
    deleteTree(root2);

    return 0;
}
