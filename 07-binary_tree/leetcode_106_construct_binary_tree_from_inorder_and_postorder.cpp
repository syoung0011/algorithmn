/**
 * LeetCode 106. 从中序与后序遍历序列构造二叉树
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 *
 * 题目：给定两个整数数组 inorder 和 postorder，其中 inorder 是二叉树的中序遍历，
 *       postorder 是同一棵树的后序遍历，请构造二叉树并返回其根节点。
 *
 * 思路：后序末元素为根，在中序中定位根并切分左右子树，递归构建
 *
 * 复杂度：时间复杂度 O(n * h)（每层拷贝/查找共 O(n)，共 h 层，按层计算，不要按节点计算；
 *        斜树时 h = n，即最坏 O(n^2)）
 *        辅助空间 O(n * h) 最坏（父层 local vector 在整棵子树递归期间一直存活），递归栈 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0106-construct-binary-tree-from-inorder-and-postorder-traversal.html
 *
 * 相关题目推荐：
 *   105. 从前序与中序遍历序列构造二叉树
 *   654. 最大二叉树
 */

#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty()) return nullptr;
        TreeNode *node = new TreeNode(postorder[postorder.size() - 1]);
        if (postorder.size() == 1) return node;
        // 这里相当于毁坏了原始数据，vector<int> post(postorder.begin(), postorder.end() - 1)更安全
        postorder.resize(postorder.size() - 1);
        int index = 0;
        // 下面假设是必定找到，也是题目约束，最安全可以加个找不到就返回null，说明数组非法
        for (; index < inorder.size(); index++) {
            if (inorder[index] == node->val) {
                break;
            }
        }
        // 这里逻辑有点复杂巧妙
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        node->left = buildTree(leftInorder, leftPostorder);
        node->right = buildTree(rightInorder, rightPostorder);
        return node;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    vector<int> postorder1 = {9, 15, 7, 20, 3};
    TreeNode *root1 = solution.buildTree(inorder1, postorder1);
    printTree(root1); // 期望输出 [3,9,20,null,null,15,7]
    deleteTree(root1); // 构造出的新树需手动释放

    // 示例 2
    vector<int> inorder2 = {-1};
    vector<int> postorder2 = {-1};
    TreeNode *root2 = solution.buildTree(inorder2, postorder2);
    printTree(root2); // 期望输出 [-1]
    deleteTree(root2);

    return 0;
}
