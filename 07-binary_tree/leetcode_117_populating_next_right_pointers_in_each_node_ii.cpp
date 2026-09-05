/**
 * LeetCode 117. 填充每个节点的下一个右侧节点指针 II
 * https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/
 *
 * 题目：给定一个二叉树，填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
 *       如果找不到下一个右侧节点，则将 next 指针设置为 NULL。初始状态下，
 *       所有 next 指针都被设置为 NULL。与 116 不同的是，本题二叉树不是完美二叉树。
 *
 * 思路：层序遍历，每层内串联 next
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(w)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/other/0116-populating-next-right-pointers-in-each-node.html
 *
 * 相关题目推荐：
 *   116. 填充每个节点的下一个右侧节点指针
 *   102. 二叉树的层序遍历
 */

#include <iostream>
#include <queue>

using namespace std;

// 带 next 指针的二叉树节点定义
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {
    }

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {
    }

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

class Solution {
public:
    Node *connect(Node *root) {
        queue<Node *> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int cnt = que.size();
            while (cnt--) {
                Node *cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
                if (cnt == 0) {
                    cur->next = nullptr;
                } else {
                    cur->next = que.front();
                }
            }
        }
        return root;
    }
};

int main() {
    Solution solution;

    // 示例：二叉树 [1,2,3,4,5,null,7]
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node7 = new Node(7);
    Node *node2 = new Node(2, node4, node5, nullptr);
    Node *node3 = new Node(3, nullptr, node7, nullptr);
    Node *root = new Node(1, node2, node3, nullptr);

    Node *result = solution.connect(root);
    if (result) {
        cout << result->left->next->val << endl; // 期望输出 3（节点2 的 next）
        cout << result->left->right->next->val << endl; // 期望输出 7（节点5 的 next）
    }

    // 释放树（层序队列只沿 left/right 入队，不碰 next，避免重复释放）
    queue<Node *> delQ;
    if (root) delQ.push(root);
    while (!delQ.empty()) {
        Node *node = delQ.front();
        delQ.pop();
        if (node->left) delQ.push(node->left);
        if (node->right) delQ.push(node->right);
        delete node;
    }

    return 0;
}
