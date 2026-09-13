/**
 * LeetCode 701. 二叉搜索树中的插入操作
 * https://leetcode.cn/problems/insert-into-a-binary-search-tree/
 *
 * 题目：给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value，将值插入
 *       二叉搜索树。返回插入后二叉搜索树的根节点。可以存在多种有效的插入方式，
 *       只要树在插入后仍保持为二叉搜索树即可。
 *
 * 思路：递归，值小于当前节点往左插，大于往右插，遇到空节点即插入位置；也可迭代
 *
 * 复杂度：时间复杂度 O(h)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0701-insert-into-a-binary-search-tree.html
 *
 * 相关题目推荐：
 *   700. 二叉搜索树中的搜索
 *   450. 删除二叉搜索树中的节点
 *   98. 验证二叉搜索树
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *cur = root; // 无需pre
        while (cur) {
            if (cur->val > val) {
                if (!cur->left) {
                    cur->left = new TreeNode(val);
                    break;
                }
                cur = cur->left;
            } else if (cur->val < val) {
                if (!cur->right) {
                    cur->right = new TreeNode(val);
                    break;
                }
                cur = cur->right;
            } else break; // 防止已有
        }
        return root;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [4,2,7,1,3]，插入 5
    TreeNode *root1 = createTree({4, 2, 7, 1, 3});
    printTree(solution.insertIntoBST(root1, 5)); // 期望输出 [4,2,7,1,3,5]
    deleteTree(root1); // 新插入的节点已挂在树上，从原 root 释放即可

    // 示例 2：空树，插入 5
    TreeNode *root2 = solution.insertIntoBST(nullptr, 5); // 期望输出 [5]
    printTree(root2);
    deleteTree(root2); // 空树插入会新建根节点，需单独释放

    return 0;
}
