/**
 * LeetCode 322. 零钱兑换
 * https://leetcode.cn/problems/coin-change/
 *
 * 题目：给你一个整数数组 coins，表示不同面额的硬币；以及一个整数 amount，表示
 *       总金额。计算并返回可以凑成总金额所需的最少的硬币个数。如果没有任何一种
 *       硬币组合能组成总金额，返回 -1。你可以认为每种硬币的数量是无限的。
 *
 * 思路：完全背包求最小个数，dp[j] 表示凑成金额 j 所需的最少硬币数，dp[j] = min(dp[j], dp[j - coins[i]] + 1)
 *
 * 复杂度：时间复杂度 O(m * amount)，空间复杂度 O(amount)（其中m为硬币个数）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0322-coin-change.html
 *
 * 相关题目推荐：
 *   518. 零钱兑换 II
 *   279. 完全平方数
 *   377. 组合总和 Ⅳ
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 初始化为最大值，递推公式天然覆盖
        vector<int> dp(amount + 1, INT_MAX);
        // dp[0]是覆盖的前提，所以他必须是正常的0
        dp[0] = 0;
        // 排列组合都可以，因为题目求的是元素个数，而不是种类个数，12 21都是2个数
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                // 要判断，不然溢出，不要用INT_MAX - 1啥的，没必要还可能错
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
        // 注意题目要求，不一定可以满足题意
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> coins1 = {1, 2, 5};
    cout << solution.coinChange(coins1, 11) << endl;  // 期望输出 3

    // 示例 2
    vector<int> coins2 = {2};
    cout << solution.coinChange(coins2, 3) << endl;  // 期望输出 -1

    // 示例 3
    vector<int> coins3 = {1};
    cout << solution.coinChange(coins3, 0) << endl;  // 期望输出 0

    return 0;
}
