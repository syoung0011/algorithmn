/**
 * LeetCode 337. 打家劫舍 III
 * https://leetcode.cn/problems/house-robber-iii/
 *
 * 题目：小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root。
 *       除了 root 之外，每栋房子有且只有一个"父"房子与之相连。一番侦察之后，聪明
 *       的小偷意识到"这个地方的所有房屋的排列类似于一棵二叉树"。如果两个直接相连的
 *       房子在同一天晚上被打劫，房屋将自动报警。给定二叉树的 root，返回在不触动警报
 *       的情况下，小偷能够盗取的最高金额。
 *
 * 思路：树形 DP 后序遍历，每个节点返回 [不偷该节点, 偷该节点] 两个状态的最大金额
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0337-house-robber-iii.html
 *
 * 相关题目推荐：
 *   TODO 暴力方法
 *   198. 打家劫舍
 *   213. 打家劫舍 II
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "tree_node.h"

using namespace std;

class Solution {
public:
    // 非常规dp，是融入了二叉树遍历的，状态记录分布在每个节点，这里得知道是后序，状态起始其实在树的叶子而不是根
    // 树和递归强绑定，记住这点
    vector<int> robTree(TreeNode *cur) {
        if (!cur) return {0, 0};
        vector<int> leftDP = robTree(cur->left);
        vector<int> rightDP = robTree(cur->right);
        int val1 = leftDP[0] + rightDP[0] + cur->val;
        // 这里需要理解，这里其实2*2=4种选择，但是这个式子就直接取最大的一个，很神奇
        int val2 = max(leftDP[0], leftDP[1]) + max(rightDP[0], rightDP[1]);
        return {val2, val1};
    }

    int rob(TreeNode *root) {
        // 包含了root空的非法了，就不用额外判断了
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};

int main() {
    Solution solution;

    // 示例 1：root = [3,2,3,null,3,null,1]
    TreeNode *root1 = createTree({3, 2, 3, INT_MIN, 3, INT_MIN, 1});
    cout << solution.rob(root1) << endl; // 期望输出 7
    deleteTree(root1);

    // 示例 2：root = [3,4,5,1,3,null,1]
    TreeNode *root2 = createTree({3, 4, 5, 1, 3, INT_MIN, 1});
    cout << solution.rob(root2) << endl; // 期望输出 9
    deleteTree(root2);

    return 0;
}
