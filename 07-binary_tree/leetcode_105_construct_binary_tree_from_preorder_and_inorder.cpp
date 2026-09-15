/**
 * LeetCode 105. 从前序与中序遍历序列构造二叉树
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 *
 * 题目：给定两个整数数组 preorder 和 inorder，其中 preorder 是二叉树的先序遍历，
 *       inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 * 思路：前序首元素为根，在中序中定位根并切分左右子树，递归构建
 *
 * 复杂度：时间复杂度 O(n * h)（每层线性查找根 + 拷贝子数组共 O(n)，共 h 层；斜树时 h = n，
 *        即最坏 O(n^2)；不要按节点数算成 O(n)）
 *        辅助空间 O(n * h) 最坏（父层局部 vector 在整棵子树递归期间一直存活），递归栈 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0106-construct-binary-tree-from-inorder-and-postorder-traversal.html
 *
 * 相关题目推荐：
 *   106. 从中序与后序遍历序列构造二叉树
 *   654. 最大二叉树
 */

#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        // 也可以不引入额外变量，直接用node->val指代
        int val = preorder[0];
        TreeNode *node = new TreeNode(val);

        int index = 0;
        for (;index < inorder.size(); index++) {
            if (inorder[index] == val) {
                break;
            }
        }

        vector<int> leftIn(inorder.begin(), inorder.begin() + index);
        vector<int> rightIn(inorder.begin() + index + 1, inorder.end());

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + leftIn.size() + 1);
        vector<int> rightPre(preorder.begin() + leftIn.size() + 1, preorder.end());

        node->left = buildTree(leftPre, leftIn);
        node->right = buildTree(rightPre, rightIn);
        return node;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    TreeNode* root1 = solution.buildTree(preorder1, inorder1);
    printTree(root1);  // 期望输出 [3,9,20,null,null,15,7]
    deleteTree(root1);  // 构造出的新树需手动释放

    // 示例 2
    vector<int> preorder2 = {-1};
    vector<int> inorder2 = {-1};
    TreeNode* root2 = solution.buildTree(preorder2, inorder2);
    printTree(root2);  // 期望输出 [-1]
    deleteTree(root2);

    return 0;
}
