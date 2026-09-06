/**
 * LeetCode 111. 二叉树的最小深度
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/
 *
 * 题目：给定一个二叉树，找出其最小深度。最小深度是从根节点到最近叶子节点的
 *       最短路径上的节点数量。叶子节点是指没有子节点的节点。
 *
 * 思路：递归，注意只有单子树时不能直接取 min，需要
 *       特殊处理左右子树为空的情况；或层序遍历遇到第一个叶子即返回
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(w)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0111-minimum-depth-of-binary-tree.html
 *
 * 相关题目推荐：
 *   104. 二叉树的最大深度
 *   110. 平衡二叉树
 */

#include <iostream>
#include "tree_node.h"
#include <algorithm>   // std::max
#include <climits>     // INT_MIN
#include <queue>       // queue

using namespace std;

class Solution {
public:
    int getMinDepth(TreeNode *cur) {
        if (!cur) return 0;
        if (!cur->left) {
            return getMinDepth(cur->right) + 1;
        }
        if (!cur->right) {
            return getMinDepth(cur->left) + 1;
        }
        return min(getMinDepth(cur->right), getMinDepth(cur->left)) + 1;
    }

    int minDepth(TreeNode *root) {
        // 递归
        // return getMinDepth(root);

        queue<TreeNode *> que;
        if (root) que.push(root);
        else return 0; // 提前返回0，避免返回INTMAX
        int cur_min_height = INT_MAX;
        int height = 0;
        while (!que.empty()) {
            int cnt = que.size();
            height++;
            while (cnt--) {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right); // 不能elif
                if (!cur->left && !cur->right) {
                    cur_min_height = min(cur_min_height, height);
                    // 其实可以提前返回，因为只要第一个叶子就可以了
                }
            }
        }
        return cur_min_height;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [3,9,20,null,null,15,7]
    TreeNode *root1 = createTree({3, 9, 20, INT_MIN, INT_MIN, 15, 7});
    cout << solution.minDepth(root1) << endl; // 期望输出 2
    deleteTree(root1);

    // 示例 2：树 [2,null,3,null,4,null,5,null,6]
    TreeNode *root2 = createTree({2, INT_MIN, 3, INT_MIN, 4, INT_MIN, 5, INT_MIN, 6});
    cout << solution.minDepth(root2) << endl; // 期望输出 5
    deleteTree(root2);

    return 0;
}
