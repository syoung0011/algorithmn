/**
 * LeetCode 121. 买卖股票的最佳时机
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 *
 * 题目：给定一个数组 prices，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的
 *       价格。你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该
 *       股票。设计一个算法来计算你所能获取的最大利润。返回你可以从这笔交易中获取
 *       的最大利润。如果你不能获取任何利润，返回 0。
 *
 * 思路：dp[i][0] 持有股票、dp[i][1] 不持有股票的最大利润，只需一次买卖
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)（可滚动优化）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0121-best-time-to-buy-and-sell-stock.html
 *
 * 相关题目推荐：
 *   TODO 暴力解法（单向最值，而不是左边找最小，右边找最大）
 *   122. 买卖股票的最佳时机 II
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
        // 前者持有，后者不持有
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        // 什么时候多维dp，就是对于每个状态，其状态选择不唯一，比如股票可以是持有和不持有
        for (int i = 1; i < prices.size(); i++) {
            // 一直是负数，而且可能和dp[x][1]不是同步的
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            // dp[i - 1][1]就包含了前面卖了，所以这个max覆盖所有状态
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }
        return dp[prices.size() - 1][1];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(prices1) << endl; // 期望输出 5

    // 示例 2
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(prices2) << endl; // 期望输出 0

    return 0;
}
