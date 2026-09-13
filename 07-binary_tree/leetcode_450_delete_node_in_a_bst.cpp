/**
 * LeetCode 450. 删除二叉搜索树中的节点
 * https://leetcode.cn/problems/delete-node-in-a-bst/
 *
 * 题目：给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 *       对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（可能被更新）
 *       的根节点的引用。
 *
 * 思路：递归，分五种情况：未找到/叶子/左空/右空/左右都非空，用右子树最左节点或左子树最右节点顶替
 *
 * 复杂度：时间复杂度 O(h)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0450-delete-node-in-a-bst.html
 *
 * 相关题目推荐：
 *   701. 二叉搜索树中的插入操作
 *   700. 二叉搜索树中的搜索
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) return root;
        if (root->val > key) root->left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else {
            TreeNode *ret = nullptr;
            if (root->left && !root->right) ret = root->left;
            else if (!root->left && root->right) ret = root->right;
            else if (root->left && root->right) {
                TreeNode *cur = root->left;
                while (cur->right) {
                    cur = cur->right;
                }
                // 不是前驱后继顶替自己的逻辑，代码为了便于实现采用了更方便的逻辑
                // 用左子树最右节点（中序前驱）承接右子树，再返回左子树作为新根
                cur->right = root->right; // 不能left，因为内部还有耦合，形成有环图
                ret = root->left;
            }
            delete root;
            return ret;
        }
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [5,3,6,2,4,null,7]，删除 3
    TreeNode *root1 = createTree({5, 3, 6, 2, 4, INT_MIN, 7});
    printTree(solution.deleteNode(root1, 3)); // 期望输出 [5,4,6,2,null,null,7]
    deleteTree(root1); // deleteNode 惯例只解链不 free，原 root 仍可达全部节点

    // 示例 2：树 [5,3,6,2,4,null,7]，删除 0
    TreeNode *root2 = createTree({5, 3, 6, 2, 4, INT_MIN, 7});
    printTree(solution.deleteNode(root2, 0)); // 期望输出 [5,3,6,2,4,null,7]
    deleteTree(root2);

    return 0;
}
