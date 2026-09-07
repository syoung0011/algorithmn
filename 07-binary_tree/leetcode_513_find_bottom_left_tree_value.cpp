/**
 * LeetCode 513. 找树左下角的值
 * https://leetcode.cn/problems/find-bottom-left-tree-value/
 *
 * 题目：给定一个二叉树的根节点 root，请找出该二叉树最底层最左边节点的值。
 *
 * 思路：层序遍历，从右往左入队，最后一个出队的节点即答案；
 *       或递归记录最大深度对应的最左节点
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0513-find-bottom-left-tree-value.html
 *
 * 相关题目推荐：
 *   102. 二叉树的层序遍历
 *   515. 在每个树行中找最大值
 */

#include <iostream>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    // 参数有点太多了，可以提出几个作为全局变量，会更加简洁
    void getLeftValue(TreeNode *cur, int &cur_max_depth, int depth, int &data) {
        if (!cur) return;
        // 去掉前两个判断也可以，就是更新会更频繁，但加上更合逻辑
        if (!cur->left && !cur->right && depth > cur_max_depth) {
            data = cur->val;
            cur_max_depth = depth;
        }
        getLeftValue(cur->left, cur_max_depth, depth + 1, data);
        getLeftValue(cur->right, cur_max_depth, depth + 1, data);
    }

    int findBottomLeftValue(TreeNode *root) {
        // 初始一定是0，考虑到单独根节点的情形
        int cur_max_depth = 0;
        int data = 0;
        // 深度初始1
        getLeftValue(root, cur_max_depth, 1, data);
        return data;
    }
};

int main() {
    Solution solution;

    // 示例 1：树 [2,1,3]
    TreeNode *root1 = createTree({2, 1, 3});
    cout << solution.findBottomLeftValue(root1) << endl; // 期望输出 1
    deleteTree(root1);

    // 示例 2：树 [1,2,3,4,null,5,6,null,null,7]
    TreeNode *root2 = createTree({1, 2, 3, 4, INT_MIN, 5, 6, INT_MIN, INT_MIN, 7});
    cout << solution.findBottomLeftValue(root2) << endl; // 期望输出 7
    deleteTree(root2);

    return 0;
}
