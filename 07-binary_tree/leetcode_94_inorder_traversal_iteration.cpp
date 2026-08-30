/**
 * LeetCode 94. 二叉树的中序遍历（迭代法）
 * https://leetcode.cn/problems/binary-tree-inorder-traversal/
 *
 * 题目：给你二叉树的根节点 root，返回它节点值的中序遍历（左 -> 根 -> 右）。
 *       本文件使用迭代法实现。
 *
 * 思路：栈 + 指针，先一路向左压栈，出栈后转向右子树
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/iterative-binary-tree-traversal.html
 *
 * 相关题目推荐：
 *   TODO 三种遍历的统一迭代法
 *   144. 二叉树的前序遍历
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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> res;
        // cur控制何时出栈，出栈后如何调整，不会导致重复入栈就很巧妙
        // 中序独有逻辑，会难一点，不是很好理解性记忆，可能要背住
        TreeNode *cur = root;
        while (cur || !st.empty()) {
            // 也许能while？那后面逻辑也要判空，就没有很好用上大while的限制
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
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

    // 示例 2：树 [1]
    TreeNode *root2 = createTree({1});
    for (int num: solution.inorderTraversal(root2)) {
        cout << num << " "; // 期望输出 1
    }
    cout << endl;
    deleteTree(root2);

    return 0;
}
