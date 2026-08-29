/**
 * LeetCode 145. 二叉树的后序遍历
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/
 *
 * 题目：给你二叉树的根节点 root，返回它节点值的后序遍历（左 -> 右 -> 根）。
 *
 * 思路：递归法，先递归左右子树再访问根节点
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/recursive-binary-tree-traversal.html
 *
 * 相关题目推荐：
 *   144. 二叉树的前序遍历
 *   94. 二叉树的中序遍历
 *   590. N 叉树的后序遍历
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
        traversal(cur->right, vec);
        vec.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,null,2,3]
    TreeNode *root1 = createTree({1, INT_MIN, 2, 3});
    for (int num: solution.postorderTraversal(root1)) {
        cout << num << " "; // 期望输出 3 2 1
    }
    cout << endl;
    deleteTree(root1);

    // 示例 2：空树
    for (int num: solution.postorderTraversal(nullptr)) {
        cout << num << " "; // 期望输出为空
    }
    cout << endl;

    // 示例 3：树 [1]
    TreeNode *root3 = createTree({1});
    for (int num: solution.postorderTraversal(root3)) {
        cout << num << " "; // 期望输出 1
    }
    cout << endl;
    deleteTree(root3);

    return 0;
}
