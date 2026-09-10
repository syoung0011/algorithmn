/**
 * LeetCode 98. 验证二叉搜索树
 * https://leetcode.cn/problems/validate-binary-search-tree/
 *
 * 题目：给你一个二叉树的根节点 root，判断其是否是一个有效的二叉搜索树。
 *       有效 BST 定义：节点的左子树只包含小于当前节点的数；节点的右子树只包含
 *       大于当前节点的数；所有左子树和右子树自身必须也是二叉搜索树。
 *
 * 思路：中序遍历应严格递增，用前驱节点比较；或递归传递上下界
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0098-validate-binary-search-tree.html
 *
 * 相关题目推荐：
 *   530. 二叉搜索树的最小绝对差
 *   501. 二叉搜索树中的众数
 *   700. 二叉搜索树中的搜索
 */

#include <iostream>
#include "tree_node.h"
#include <climits>

using namespace std;

// 递归法，三种方法：
// 一种就是我这样，开新变量，繁
// 一种是也用last，不过是longlongmin，这样就可省去flag，因为首节点就不会和最小值相等了，但万一数据集改变，这个方法会失效
// 一种是回归本质，不记录值，而是节点地址，初始化为null。最为推荐，因为本质就是当前和上一个指针的比较
// 迭代法，直接存到数组里面然后从第二项开始判断升序，也可以避免上述问题

int last = INT_MIN;
int flag = true;

class Solution {
public:
    bool inOrder(TreeNode *cur) {
        bool left = true, right = true;
        if (cur->left) left = inOrder(cur->left);
        if (cur->val <= last) {
            // 外面有个!，是因为这个写法不用写空语句会好看点，但逻辑没法想，所以也没化简逻辑表达式
            if (!(cur->val == INT_MIN && flag)) return false;
        }
        flag = false; // 注意位置，放在if里面会丧失flag标记是否是根节点的初衷
        last = cur->val;
        if (cur->right) right = inOrder(cur->right);
        return left && right;
    }

    bool isValidBST(TreeNode *root) {
        if (!root) return false;
        last = INT_MIN;
        flag = true;
        return inOrder(root);
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [2,1,3]
    TreeNode *root1 = createTree({2, 1, 3});
    cout << (solution.isValidBST(root1) ? "true" : "false") << endl; // 期望输出 true
    deleteTree(root1);

    // 示例 2：树 [5,1,4,null,null,3,6]
    TreeNode *root2 = createTree({5, 1, 4, INT_MIN, INT_MIN, 3, 6});
    cout << (solution.isValidBST(root2) ? "true" : "false") << endl; // 期望输出 false
    deleteTree(root2);

    return 0;
}
