/**
 * LeetCode 429. N 叉树的层序遍历
 * https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
 *
 * 题目：给定一个 N 叉树，返回其节点值的层序遍历。N 叉树在输入中按层序遍历进行
 *       序列化表示，每组子节点由空值 null 分隔。
 *
 * 思路：队列辅助，每层遍历全部子节点入队
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(w)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0102-binary-tree-level-order-traversal.html
 *
 * 相关题目推荐：
 *   102. 二叉树的层序遍历
 *   589. N 叉树的前序遍历
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// N 叉树节点定义
class Node {
public:
    int val;
    vector<Node*> children;

    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> que;
        if (root) que.push(root);
        vector<vector<int>> vec;
        while (!que.empty()) {
            int cnt = que.size();
            vector<int> level_vec;
            while (cnt--) {
                Node *cur = que.front();
                que.pop();
                level_vec.push_back(cur->val);
                // childern保底是空容器，不是空指针，不用担心报错，况且range-for也是专为容器设计
                for (auto child : cur->children) {
                    que.push(child);
                }
            }
            vec.push_back(level_vec);
        }
        return vec;
    }
};

int main() {
    Solution solution;

    // 示例：手写构造 N 叉树 [1,null,3,2,4,null,5,6]
    Node* node3 = new Node(3);
    node3->children = {new Node(5), new Node(6)};
    Node* root = new Node(1, {node3, new Node(2), new Node(4)});

    for (const auto& level : solution.levelOrder(root)) {
        for (int num : level) {
            cout << num << " ";  // 期望输出 1 / 3 2 4 / 5 6
        }
        cout << endl;
    }

    // 释放 N 叉树（栈式遍历，逐节点连同子节点一起释放）
    vector<Node*> delStack = {root};
    while (!delStack.empty()) {
        Node* node = delStack.back();
        delStack.pop_back();
        if (!node) continue;
        for (Node* child : node->children) {
            delStack.push_back(child);
        }
        delete node;
    }

    return 0;
}
