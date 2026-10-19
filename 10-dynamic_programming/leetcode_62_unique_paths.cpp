/**
 * LeetCode 62. 不同路径
 * https://leetcode.cn/problems/unique-paths/
 *
 * 题目：一个机器人位于一个 m x n 网格的左上角。机器人每次只能向下或者向右移动
 *       一步。机器人试图达到网格的右下角。问总共有多少条不同的路径？
 *
 * 思路：动态规划，dp[i][j] = dp[i-1][j] + dp[i][j-1]，第一行第一列初始化为 1；可用组合数 C(m+n-2, m-1) 直接求解
 *
 * 复杂度：时间复杂度 O(mn)，空间复杂度 O(mn)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0062-unique-paths.html
 *
 * 相关题目推荐：
 *   63. 不同路径 II
 *   64. 最小路径和
 *   120. 三角形最小路径和
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n));
        // 官网是先遍历初始化第一行第一列，这样更规范
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.uniquePaths(3, 7) << endl; // 期望输出 28

    // 示例 2
    cout << solution.uniquePaths(3, 2) << endl; // 期望输出 3

    return 0;
}
