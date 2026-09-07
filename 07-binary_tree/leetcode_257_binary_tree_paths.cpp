/**
 * LeetCode 257. 二叉树的所有路径
 * https://leetcode.cn/problems/binary-tree-paths/
 *
 * 题目：给你一个二叉树的根节点 root，按任意顺序返回所有从根节点到叶子节点的路径。
 *
 * 思路：回溯法，前序遍历收集路径，到叶子节点时拼接结果
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0257-binary-tree-paths.html
 *
 * 相关题目推荐：
 *   TODO string path
 *   112. 路径总和
 *   113. 路径总和 II
 */

#include <iostream>
#include <string>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    void preOrder(TreeNode *cur, vector<int> &path, vector<string> &res) {
        path.push_back(cur->val);
        if (!cur->left && !cur->right) {
            string s = to_string(path[0]);
            for (int i = 1; i < path.size(); i++) {
                s += "->";
                s += to_string(path[i]);
            }
            res.push_back(s);
            // 两处pop,不是很规范,但是能用
            path.pop_back();
            return;
        }
        if (cur->left) preOrder(cur->left, path, res);
        if (cur->right) preOrder(cur->right, path, res);
        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) return {};
        vector<int> path;
        vector<string> res;
        preOrder(root, path, res);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,2,3,null,5]
    TreeNode *root1 = createTree({1, 2, 3, INT_MIN, 5});
    for (const string &path: solution.binaryTreePaths(root1)) {
        cout << path << endl; // 期望输出 1->2->5 和 1->3
    }
    deleteTree(root1);

    // 示例 2：树 [1]
    TreeNode *root2 = createTree({1});
    for (const string &path: solution.binaryTreePaths(root2)) {
        cout << path << endl; // 期望输出 1
    }
    deleteTree(root2);

    return 0;
}
