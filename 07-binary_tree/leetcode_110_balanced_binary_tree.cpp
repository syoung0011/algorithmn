/**
 * LeetCode 110. 平衡二叉树
 * https://leetcode.cn/problems/balanced-binary-tree/
 *
 * 题目：给定一个二叉树，判断它是否是高度平衡的二叉树。本题中，一棵高度平衡
 *       二叉树定义为：一个二叉树每个节点的左右两个子树的高度差的绝对值不超过 1。
 *
 * 思路：自顶向下，先求左右子树高度再递归判断
 *
 * 复杂度：时间复杂度 O(n * h)（自顶向下，每个节点都要重算一次子树高度：每层求高 O(n)，
 *        共 h 层；平衡树 h = log n 即 O(n log n)，斜树 h = n 即 O(n^2)）
 *        空间复杂度 O(h)（递归栈）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0110-balanced-binary-tree.html
 *
 * 相关题目推荐：
 *   TODO 后序 -1 哨兵版,时间效率更高
 *   104. 二叉树的最大深度
 *   111. 二叉树的最小深度
 */

#include <iostream>
#include "tree_node.h"
#include <algorithm>   // std::max
#include <cstdlib>  // 显示包含，abs

using namespace std;

class Solution {
public:
    int getDepth(TreeNode *cur) {
        if (!cur) return 0;
        return max(getDepth(cur->left), getDepth(cur->right)) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int leftHeight = getDepth(root->left);
        int rightHeight = getDepth(root->right);
        // 写法一
        // return abs(leftHeight - rightHeight) < 2 && isBalanced(root->left) && isBalanced(root->right);

        // 写法二,和上面等价
        if (abs(leftHeight - rightHeight) < 2) {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }

    // 写法三,确实后序,但复杂度仍然不变,与-1 后序不同
    bool isBalancedPostorder(TreeNode *root) {
        if (!root) return true;
        bool t1 = isBalancedPostorder(root->left);
        bool t2 = isBalancedPostorder(root->right);
        if (t1 && t2) {
            int leftHeight = getDepth(root->left);
            int rightHeight = getDepth(root->right);
            if (abs(leftHeight - rightHeight) < 2) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [3,9,20,null,null,15,7]
    TreeNode *root1 = createTree({3, 9, 20, INT_MIN, INT_MIN, 15, 7});
    cout << (solution.isBalanced(root1) ? "true" : "false") << endl; // 期望输出 true
    deleteTree(root1);

    // 示例 2：树 [1,2,2,3,3,null,null,4,4]
    TreeNode *root2 = createTree({1, 2, 2, 3, 3, INT_MIN, INT_MIN, 4, 4});
    cout << (solution.isBalanced(root2) ? "true" : "false") << endl; // 期望输出 false
    deleteTree(root2);

    return 0;
}
