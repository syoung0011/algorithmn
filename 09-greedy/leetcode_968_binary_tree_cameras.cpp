/**
 * LeetCode 968. 监控二叉树
 * https://leetcode.cn/problems/binary-tree-cameras/
 *
 * 题目：给定一个二叉树，我们在树的节点上安装摄像头。节点上的每个摄影头都可以
 *       监视其父对象、自身及其直接子对象。计算监控树的所有节点所需的最小摄像头
 *       数量。
 *
 * 思路：贪心 + 后序遍历，节点状态分三种：无覆盖 0、有摄像头 1、有覆盖 2；叶子节点父节点放摄像头最优
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0968-binary-tree-cameras.html
 *
 * 相关题目推荐：
 *   337. 打家劫舍 III
 *   979. 在二叉树中分配硬币
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    int postOrder(TreeNode *cur, int &result) {
        // 为了满足解法让null带有特殊含义
        if (cur == nullptr) return 2;
        int left = postOrder(cur->left, result);
        int right = postOrder(cur->right, result);
        // 这里很巧妙，逻辑，且排列最好是这样，不然可能报错，有个内在优先
        if (right == 2 && left == 2) return 0;
        if (right == 0 || left == 0) {
            result++;
            return 1;
        }
        if (right == 1 || left == 1) return 2;
        // 占位，避免报错
        return -1;
    }

    int minCameraCover(TreeNode *root) {
        int result = 0;
        // 本算法是递归返回值联系的，节点没有任何改动，所以没法用root. == ...而是直接后序返回值
        if (postOrder(root, result) == 0) {
            result++;
        }
        return result;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [0,0,null,0,0]
    TreeNode *root1 = createTree({0, 0, INT_MIN, 0, 0});
    cout << solution.minCameraCover(root1) << endl; // 期望输出 1
    deleteTree(root1);

    // 示例 2：树 [0,0,null,0,null,0,null,null,0]
    TreeNode *root2 = createTree({0, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, INT_MIN, 0});
    cout << solution.minCameraCover(root2) << endl; // 期望输出 2
    deleteTree(root2);

    return 0;
}
