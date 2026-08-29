/**
 * LeetCode 94. 二叉树的中序遍历
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/
 *
 * 题目：给你二叉树的根节点 root，返回它节点值的中序遍历（左 -> 根 -> 右）。
 *
 * 思路：递归法，先递归左子树再访问根节点最后递归右子树
 *
 * 复杂度：时间复杂度 O(n)；空间复杂度 O(h)，h 为树高，平衡树 O(log n)，最坏（斜树）O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/recursive-binary-tree-traversal.html
 *
 * 相关题目推荐：
 *   144. 二叉树的前序遍历
 *   145. 二叉树的后序遍历
 *   98. 验证二叉搜索树
 */

#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    void traversal(TreeNode *cur, vector<int> &vec) {
        if (cur == nullptr) {
            return;
        }
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        // 递归过程外包
        traversal(root, res);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,null,2,3]
    TreeNode *root1 = createTree({1, INT_MIN, 2, 3});
    for (int num: solution.inorderTraversal(root1)) {
        cout << num << " "; // 期望输出 1 3 2
    }
    cout << endl;
    deleteTree(root1);

    // 示例 2：空树
    for (int num: solution.inorderTraversal(nullptr)) {
        cout << num << " "; // 期望输出为空
    }
    cout << endl;

    // 示例 3：树 [1]
    TreeNode *root3 = createTree({1});
    for (int num: solution.inorderTraversal(root3)) {
        cout << num << " "; // 期望输出 1
    }
    cout << endl;
    deleteTree(root3);

    return 0;
}
