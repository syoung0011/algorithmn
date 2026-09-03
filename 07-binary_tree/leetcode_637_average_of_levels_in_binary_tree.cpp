/**
 * LeetCode 637. 二叉树的层平均值
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/
 *
 * 题目：给定一个非空二叉树的根节点 root，以数组的形式返回每一层节点的平均值。
 *       与实际答案相差 10^-5 以内的答案可以被接受。
 *
 * 思路：层序遍历，每层求和取平均
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
    vector<double> averageOfLevels(TreeNode *root) {
        queue<TreeNode *> que;
        if (root) que.push(root);
        // vector<vector<int>> vec; // 这里不要，区别于层次遍历模板
        vector<double> res; // 相较层次遍历新增的内容
        while (!que.empty()) {
            int cnt = que.size();
            vector<int> level_vec; // 每趟循环自动重置，无需clear
            while (cnt--) {
                TreeNode *cur = que.front();
                que.pop();
                level_vec.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            // vec.push_back(level_vec); // 这里不要，区别于层次遍历模板
            // 以下相较层次遍历新增的内容，求和也可融入出队，更加简洁
            long long sum = 0; // 警惕，用int会溢出
            for (int num: level_vec) {
                sum += num;
            }
            // 必须局部强转，不能对整体double强转。double x=...都也不行，因为右边求平均运算已经折损了
            res.push_back((double) sum / level_vec.size());
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [3,9,20,null,null,15,7]
    TreeNode *root1 = createTree({3, 9, 20, INT_MIN, INT_MIN, 15, 7});
    for (double avg: solution.averageOfLevels(root1)) {
        cout << avg << " "; // 期望输出 3 14.5 11
    }
    cout << endl;
    deleteTree(root1);

    // 示例 2：树 [3,9,20,15,7]
    TreeNode *root2 = createTree({3, 9, 20, 15, 7});
    for (double avg: solution.averageOfLevels(root2)) {
        cout << avg << " "; // 期望输出 3 14.5 11
    }
    cout << endl;
    deleteTree(root2);

    return 0;
}
