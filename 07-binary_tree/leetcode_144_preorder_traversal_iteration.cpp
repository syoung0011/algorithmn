/**
 * LeetCode 144. 二叉树的前序遍历（迭代法）
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/
 *
 * 题目：给你二叉树的根节点 root，返回它节点值的前序遍历（根 -> 左 -> 右）。
 *       本文件使用迭代法实现。
 *
 * 思路：显式栈模拟，先压右孩子再压左孩子，出栈顺序即为前序
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/iterative-binary-tree-traversal.html
 *
 * 相关题目推荐：
 *   94. 二叉树的中序遍历
 *   145. 二叉树的后序遍历
 *   102. 二叉树的层序遍历
 */

#include <iostream>
#include <stack>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        // 拦截空，保证栈内都是不空的地址，与官网不同，但官网逻辑更清晰
        if (!root) return {};
        stack<TreeNode *> st;
        vector<int> res;
        st.push(root);
        while (!st.empty()) {
            TreeNode *top = st.top();
            st.pop();
            if (top->right) st.push(top->right);
            if (top->left) st.push(top->left);
            res.push_back(top->val);
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [1,null,2,3]
    TreeNode *root1 = createTree({1, INT_MIN, 2, 3});
    for (int num: solution.preorderTraversal(root1)) {
        cout << num << " "; // 期望输出 1 2 3
    }
    cout << endl;
    deleteTree(root1);

    // 示例 2：树 [1]
    TreeNode *root2 = createTree({1});
    for (int num: solution.preorderTraversal(root2)) {
        cout << num << " "; // 期望输出 1
    }
    cout << endl;
    deleteTree(root2);

    return 0;
}
