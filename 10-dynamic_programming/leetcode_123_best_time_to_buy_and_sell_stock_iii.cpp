/**
 * LeetCode 123. 买卖股票的最佳时机 III
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
 *
 * 题目：给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。设计一个算法
 *       来计算你所能获取的最大利润。你最多可以完成两笔交易。注意：你不能同时参与
 *       多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * 思路：dp[i][k] 表示第 i 天处于第 k 种状态（首次持有、首次不持有、二次持有、二次不持有）的最大利润
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0123-best-time-to-buy-and-sell-stock-iii.html
 *
 * 相关题目推荐：
 *   TODO 状态压缩优化
 *   121. 买卖股票的最佳时机
 *   122. 买卖股票的最佳时机 II
 *   188. 买卖股票的最佳时机 IV
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(5));
        // 注意顺序，必须先持有再不持有，因为有个不操作的状态，连着就会导致状态有交集之类的
        // 不操作， 第一次持有， 第一次不持有， 第二次持有， 第二次不持有（第一次指买的第一个股票）
        dp[0][1] = -prices[0];
        // 就是当天买当天卖来理解
        dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[prices.size() - 1][4];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << solution.maxProfit(prices1) << endl; // 期望输出 6

    // 示例 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << solution.maxProfit(prices2) << endl; // 期望输出 4

    // 示例 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << solution.maxProfit(prices3) << endl; // 期望输出 0

    return 0;
}
