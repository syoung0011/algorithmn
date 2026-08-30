#ifndef ALGORITHMN_TREE_NODE_H
#define ALGORITHMN_TREE_NODE_H

#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

// 二叉树节点定义（与 LeetCode / 代码随想录一致）
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

// 根据层序数组构造二叉树，INT_MIN 表示空节点
// 采用 LeetCode 紧凑层序约定：只为「真实节点」的左右孩子留槽位，
// 空节点的孩子不占槽位（不是完全二叉树的堆式索引）。
// 如 [3,9,20,INT_MIN,INT_MIN,15,7] 对应：
//        3
//       / \
//      9  20
//        /  \
//       15   7
// 又如 [1,INT_MIN,2,3]：1 无左孩子、右孩子为 2，2 的左孩子为 3
// （写成 [1,INT_MIN,2,INT_MIN,INT_MIN,3] 是堆式索引，属错误用法）
inline TreeNode *createTree(const std::vector<int> &values) {
    if (values.empty()) {
        return nullptr;
    }
    TreeNode *root = new TreeNode(values[0]);
    std::queue<TreeNode *> q;
    q.push(root);
    size_t i = 1;
    // 队列空说明数组还有多余元素（常见于误用堆式索引写法），
    // 此时停止建树并忽略多余元素，避免空队列上调用 front() 导致未定义行为
    while (i < values.size() && !q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (i < values.size() && values[i] != INT_MIN) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        ++i;
        if (i < values.size() && values[i] != INT_MIN) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}

// 层序遍历打印（末尾空节点不输出），如 [3,9,20,null,null,15,7]
inline void printTree(TreeNode *root) {
    if (!root) {
        std::cout << "null" << std::endl;
        return;
    }
    std::queue<TreeNode *> q;
    q.push(root);
    std::vector<std::string> out;
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node) {
            out.push_back(std::to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else {
            out.push_back("null");
        }
    }
    while (!out.empty() && out.back() == "null") {
        out.pop_back();
    }
    std::cout << "[";
    for (size_t i = 0; i < out.size(); ++i) {
        if (i > 0) {
            std::cout << ",";
        }
        std::cout << out[i];
    }
    std::cout << "]" << std::endl;
}

// 释放二叉树内存（后序遍历）
inline void deleteTree(TreeNode *root) {
    if (!root) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

#endif // ALGORITHMN_TREE_NODE_H
