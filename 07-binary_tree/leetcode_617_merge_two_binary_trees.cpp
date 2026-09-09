/**
 * LeetCode 617. 合并二叉树
 * https://leetcode.cn/problems/merge-two-binary-trees/
 *
 * 题目：给你两棵二叉树 root1 和 root2，想象一下当你将其中一棵覆盖到另一棵之上时，
 *       两棵树上的一些节点会重叠而另一些不会。合并规则是：如果两个节点重叠，
 *       那么将这两个节点的值相加作为合并后节点的新值；否则不为 null 的节点将
 *       直接作为新二叉树的节点。返回合并后的二叉树。
 *
 * 思路：递归，重叠节点求和，一边为空则直接返回另一边
 *
 * 复杂度：时间复杂度 O(n1 + n2)，空间复杂度 O(h1 + h2)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0617-merge-two-binary-trees.html
 *
 * 相关题目推荐：
 *   100. 相同的树
 *   226. 翻转二叉树
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    TreeNode *preOrder(TreeNode *t1, TreeNode *t2) {
        TreeNode *ret = nullptr;
        if (t1 && t2) {
            t1->val += t2->val;
            ret = t1;
            t1->left = preOrder(t1->left, t2->left);
            t1->right = preOrder(t1->right, t2->right);
            delete t2;
            t2 = nullptr; // 其实无用，外界指针无法同步，因为值传递
        } else if (!t1 && t2) {
            ret = t2;
        } else if (t1 && !t2) {
            ret = t1;
        }
        return ret;
    }

    // FIXME 写法有一定问题，具体见笔记，暂时跳过。
    // 有的时候可以牺牲内存，也就是故意内存泄漏，换取稳定性与通过率
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        return preOrder(root1, root2);
    }
};

int main() {
    Solution solution;

    // 示例 1
    TreeNode *root1 = createTree({1, 3, 2, 5});
    TreeNode *root2 = createTree({2, 1, 3, INT_MIN, 4, INT_MIN, 7});
    printTree(solution.mergeTrees(root1, root2)); // 期望输出 [3,4,5,5,4,null,7]
    // 标准实现就地修改 root1 并复用 root2 的节点，只能从 root1 释放一次，
    // 若再 deleteTree(root2) 会对被复用的节点二次释放
    deleteTree(root1);

    // 示例 2
    TreeNode *root3 = createTree({1});
    TreeNode *root4 = createTree({1, 2});
    printTree(solution.mergeTrees(root3, root4)); // 期望输出 [2,2]
    deleteTree(root3); // 同上，root4 的节点已被并入 root3

    return 0;
}
