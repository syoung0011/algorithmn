/**
 * LeetCode 279. 完全平方数
 * https://leetcode.cn/problems/perfect-squares/
 *
 * 题目：给你一个整数 n，返回和为 n 的完全平方数的最少数量。完全平方数是一个整数，
 *       其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、
 *       9 和 16 都是完全平方数，而 3 和 11 不是。
 *
 * 思路：完全背包求最小个数，物品为完全平方数，容量为 n，dp[j] = min(dp[j], dp[j - i * i] + 1)
 *
 * 复杂度：时间复杂度 O(n^{3/2})，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0279-perfect-squares.html
 *
 * 相关题目推荐：
 *   322. 零钱兑换
 *   518. 零钱兑换 II
 */

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        int up = sqrt(n);
        // 别忘了
        dp[0] = 0;
        // 抽象物品，不是真正物品(i^2)
        for (int i = 1; i <= up; i++) {
            int weight = i * i;
            // 不是 j = 1开始，老犯低级错
            for (int j = weight; j <= n; j++) {
                if (dp[j - weight] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - weight] + 1);
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.numSquares(12) << endl; // 期望输出 3（4+4+4）

    // 示例 2
    cout << solution.numSquares(13) << endl; // 期望输出 2（4+9）

    return 0;
}
