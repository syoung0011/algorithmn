/**
 * LeetCode 145. 二叉树的后序遍历（迭代法）
 * https://leetcode.cn/problems/binary-tree-postorder-traversal/
 *
 * 题目：给你二叉树的根节点 root，返回它节点值的后序遍历（左 -> 右 -> 根）。
 *       本文件使用迭代法实现。
 *
 * 思路：前序遍历反转，或栈 + 标记法区分已访问节点
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/iterative-binary-tree-traversal.html
 *
 * 相关题目推荐：
 *   144. 二叉树的前序遍历
 *   94. 二叉树的中序遍历
 *   102. 二叉树的层序遍历
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // 直接复用先序的逻辑，改动下入栈顺序，添加下反转过程（根右左 -> 左右根）
        // 但其实这里是小巧思，对结果集下手，不然只用这套逻辑是无法实现的，类似中序，需要改变逻辑
        if (!root) return {};
        stack<TreeNode *> st;
        vector<int> res;
        st.push(root);
        while (!st.empty()) {
            TreeNode *top = st.top();
            st.pop();
            if (top->left) st.push(top->left);
            if (top->right) st.push(top->right);
            res.push_back(top->val);
        }
        reverse(res.begin(), res.end());
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

    // 示例 2：树 [1]
    TreeNode *root2 = createTree({1});
    for (int num: solution.postorderTraversal(root2)) {
        cout << num << " "; // 期望输出 1
    }
    cout << endl;
    deleteTree(root2);

    return 0;
}
