/**
 * LeetCode 501. 二叉搜索树中的众数
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/
 *
 * 题目：给你一个含重复值的二叉搜索树（BST）的根节点 root，找出并返回 BST 中
 *       的所有众数（出现频率最高的元素）。如果树中有不止一个众数，可以按任意
 *       顺序返回。
 *
 * 思路：中序遍历递增有序，统计连续相同值出现的次数，动态更新众数集合；或先哈希统计再找最大值
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0501-find-mode-in-binary-search-tree.html
 *
 * 相关题目推荐：
 *   530. 二叉搜索树的最小绝对差
 *   98. 验证二叉搜索树
 */

#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;

int curMaxCnt = 0;
vector<int> res;
int cnt = 0;
TreeNode *pre = nullptr;

class Solution {
public:
    void traversal(TreeNode *cur) {
        if (!cur) return;
        traversal(cur->left);
        if (!pre) {
            cnt = 1;
        } else if (pre->val == cur->val) {
            cnt++;
        } else {
            cnt = 1;
        }
        pre = cur;
        if (cnt > curMaxCnt) {
            res.clear();
            res.push_back(cur->val);
            curMaxCnt = cnt;
        } else if (cnt == curMaxCnt) {
            res.push_back(cur->val);
        }
        traversal(cur->right);
    }

    vector<int> findMode(TreeNode *root) {
        res.clear();
        curMaxCnt = 0;
        pre = nullptr;
        traversal(root);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,null,2,2]
    TreeNode *root1 = createTree({1, INT_MIN, 2, 2});
    for (int num: solution.findMode(root1)) {
        cout << num << " "; // 期望输出 2
    }
    cout << endl;
    deleteTree(root1);

    // 示例 2：树 [0]
    TreeNode *root2 = createTree({0});
    for (int num: solution.findMode(root2)) {
        cout << num << " "; // 期望输出 0
    }
    cout << endl;
    deleteTree(root2);

    return 0;
}
