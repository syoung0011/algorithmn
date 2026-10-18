/**
 * LeetCode 96. 不同的二叉搜索树
 * https://leetcode.cn/problems/unique-binary-search-trees/
 *
 * 题目：给你一个整数 n，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的二叉
 *       搜索树有多少种？返回满足题意的二叉搜索树的种数。
 *
 * 思路：动态规划，dp[n] = sum(dp[j-1] * dp[n-j])，j 为根节点，左右子树分别有 j-1 和 n-j 个节点
 *
 * 复杂度：时间复杂度 O(n^2)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0096-unique-binary-search-trees.html
 *
 * 相关题目推荐：
 *   95. 不同的二叉搜索树 II
 *   241. 为运算表达式设计优先级
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            // 官网的j含义更好，是以节点的值来定义的，我这里按个数，其实也还可以
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.numTrees(3) << endl; // 期望输出 5

    // 示例 2
    cout << solution.numTrees(1) << endl; // 期望输出 1

    return 0;
}
