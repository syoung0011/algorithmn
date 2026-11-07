/**
 * LeetCode 714. 买卖股票的最佳时机含手续费
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 *
 * 题目：给定一个整数数组 prices，其中 prices[i] 表示第 i 天的股票价格；整数 fee
 *       代表了交易股票的手续费用。你可以无限次地完成交易，但是你每笔交易都需要付
 *       手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 *       返回获得利润的最大值。
 *
 * 思路：无限次交易，卖出时扣除手续费，dp[i][0] 持有 / dp[i][1] 不持有的最大利润
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0714-best-time-to-buy-and-sell-stock-with-transaction-fee-dynamic-programming.html
 *
 * 相关题目推荐：
 *   122. 买卖股票的最佳时机 II
 *   309. 最佳买卖股票时机含冷冻期
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        // 持有， 不持有
        // 注意fee在卖出计算，这样初始化会简单些，因为持有股还没卖，dp01直接为0就行，所以注意审题和等价转换
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        // 这里可能要max一下，万一fee太大，那还不如不卖了
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][0]);
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> prices1 = {1, 3, 2, 8, 4, 9};
    cout << solution.maxProfit(prices1, 2) << endl;  // 期望输出 8

    // 示例 2
    vector<int> prices2 = {1, 3, 7, 5, 10, 3};
    cout << solution.maxProfit(prices2, 3) << endl;  // 期望输出 6

    return 0;
}
