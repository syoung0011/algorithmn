/**
 * LeetCode 122. 买卖股票的最佳时机 II
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 *
 * 题目：给你一个整数数组 prices，其中 prices[i] 表示某支股票第 i 天的价格。在每一天，
 *       你可以决定是否购买和/或出售股票。你在任何时候最多只能持有一股股票。然而，
 *       你可以在同一天多次买卖该股票，但要确保你持有的股票不超过一股。返回你能获得的
 *       最大利润。
 *
 * 思路：dp[i][0] 表示第 i 天持有股票的最大利润，dp[i][1] 表示
 *      第 i 天不持有股票的最大利润；与 121 题不同，本题可以多次买卖，
 *      买入时要用 dp[i - 1][1] - prices[i]，而不是 121 题的 -prices[i]
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0122-best-time-to-buy-and-sell-stock-ii-dynamic-programming.html
 *
 * 相关题目推荐：
 *   121. 买卖股票的最佳时机
 *   123. 买卖股票的最佳时机 III
 *   188. 买卖股票的最佳时机 IV
 *   309. 最佳买卖股票时机含冷冻期
 *   714. 买卖股票的最佳时机含手续费
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 与 1 只有一处参数不同
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        return dp[prices.size() - 1][1];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(prices1) << endl; // 期望输出 7

    // 示例 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << solution.maxProfit(prices2) << endl; // 期望输出 4

    // 示例 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(prices3) << endl; // 期望输出 0

    return 0;
}
