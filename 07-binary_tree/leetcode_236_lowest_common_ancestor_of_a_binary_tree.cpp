/**
 * LeetCode 236. 二叉树的最近公共祖先
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
 *
 * 题目：给定一个二叉树，找到该树中两个指定节点的最近公共祖先。最近公共祖先
 *       定义为：对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
 *       满足 x 是 p、q 的祖先且 x 的深度尽可能大。
 *
 * 思路：后序遍历递归，左右子树都有结果则当前节点为祖先
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0236-lowest-common-ancestor-of-a-binary-tree.html
 *
 * 相关题目推荐：
 *   235. 二叉搜索树的最近公共祖先
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 判空边界还是比判空进入（即递归前判断，保证下一趟不空）简单，逻辑简单点
        // 以下两个if可以合并return root
        if (!root) return root;
        // 后序左右中，不代表root所有判断都在最后，这里边界情况是比左右优先级还高的，放在最上面
        if (root == p || root == q) {
            return root;
        }
        // 下面找着了，上面也不会修改，而是返回，保证了最近公共父节点的逻辑
        // 这个逻辑要自己想一下，其实不难理解
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 也可简化为：
        // if (left && right) return root;
        // return left ? left : right;
        if (left && right) return root;
        if (!left && right) return right;
        if (left && !right) return left;
        return nullptr;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [3,5,1,6,2,0,8,null,null,7,4]，p=5, q=1
    TreeNode *root1 = createTree({3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4});
    TreeNode *p1 = root1->left; // 值为 5
    TreeNode *q1 = root1->right; // 值为 1
    cout << solution.lowestCommonAncestor(root1, p1, q1)->val << endl; // 期望输出 3

    // 示例 2：p=5, q=4
    TreeNode *p2 = root1->left; // 值为 5
    TreeNode *q2 = root1->left->right->right; // 值为 4
    cout << solution.lowestCommonAncestor(root1, p2, q2)->val << endl; // 期望输出 5
    deleteTree(root1); // 两个示例共用同一棵树，最后统一释放

    return 0;
}
