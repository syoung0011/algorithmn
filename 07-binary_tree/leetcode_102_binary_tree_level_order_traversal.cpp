/**
 * LeetCode 102. 二叉树的层序遍历
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/
 *
 * 题目：给你二叉树的根节点 root，返回其节点值的层序遍历（即逐层地，从左到右
 *       访问所有节点）。
 *
 * 思路：队列辅助，每次记录当前层节点数，分层输出
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(w)（w 为树的最大宽度，即队列峰值大小）
 * 空间复杂度ep：完美二叉树：最底层约 n/2 个节点 → 最坏 O(n)；链状树（每层 1 个节点）：O(1)）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0102-binary-tree-level-order-traversal.html
 *
 * 相关题目推荐：
 *   107. 二叉树的层序遍历 II
 *   199. 二叉树的右视图
 *   637. 二叉树的层平均值
 *   429. N 叉树的层序遍历
 */

#include <iostream>
#include <vector>
#include <queue>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // 按题目要求，需要按层返回，不是前中后那种，结果集一个数组搞定
        if (!root) return {};
        vector<vector<int> > res;
        vector<int> level_vec;
        queue<TreeNode *> que;
        // 预装入，官网没有，所以统一处理，所以外层还有个循环
        que.push(root);
        int cnt = 1;
        while (!que.empty()) {
            TreeNode *cur = que.front();
            que.pop();
            level_vec.push_back(cur->val);
            // 入队不是改变cnt的时机，这样多层会融在一块
            if (cur->left) que.push(cur->left);
            if (cur->right) que.push(cur->right);
            if (--cnt == 0) {
                res.push_back(level_vec);
                level_vec.clear();
                // 核心特征，每一次cnt为0，栈内存放的就是下一层完整的结点，此时再更新计数器
                cnt = que.size();
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [3,9,20,null,null,15,7]
    TreeNode *root1 = createTree({3, 9, 20, INT_MIN, INT_MIN, 15, 7});
    for (const auto &level: solution.levelOrder(root1)) {
        for (int num: level) {
            cout << num << " "; // 期望输出 3 / 9 20 / 15 7
        }
        cout << endl;
    }
    deleteTree(root1);

    // 示例 2：空树
    for (const auto &level: solution.levelOrder(nullptr)) {
        for (int num: level) {
            cout << num << " ";
        }
        cout << endl;
    }
    // 期望输出为空

    return 0;
}
