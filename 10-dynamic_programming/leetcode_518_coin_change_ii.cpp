/**
 * LeetCode 518. 零钱兑换 II
 * https://leetcode.cn/problems/coin-change-ii/
 *
 * 题目：给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示
 *       总金额。请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都
 *       无法凑出总金额，返回 0。假设每一种面额的硬币有无限个。
 *
 * 思路：完全背包求组合数，外层遍历物品、内层遍历容量正序，dp[j] += dp[j - coins[i]]
 *
 * 复杂度：时间复杂度 O(m * n)，空间复杂度 O(n)（m为硬币种数，n为总金额）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0518-coin-change-ii.html
 *
 * 相关题目推荐：
 *   322. 零钱兑换
 *   377. 组合总和 Ⅳ
 *   279. 完全平方数
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 必须用ull才能过，中间可能会溢出int，但是结果不一定溢出，这是刚好卡了验证不让ak，这一定要谨慎
        vector<unsigned long long> dp(amount + 1); // 别写成中括号，找了半天错
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> coins1 = {1, 2, 5};
    cout << solution.change(5, coins1) << endl;  // 期望输出 4

    // 示例 2
    vector<int> coins2 = {2};
    cout << solution.change(3, coins2) << endl;  // 期望输出 0

    // 示例 3
    vector<int> coins3 = {10};
    cout << solution.change(10, coins3) << endl;  // 期望输出 1

    return 0;
}
