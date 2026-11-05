/**
 * LeetCode 188. 买卖股票的最佳时机 IV
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
 *
 * 题目：给你一个整数数组 prices 和一个整数 k，其中 prices[i] 是某支给定的股票在第
 *       i 天的价格。设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 *       也就是说，你最多可以买 k 次，卖 k 次。注意：你不能同时参与多笔交易（你必须
 *       在再次购买前出售掉之前的股票）。
 *
 * 思路：123 题的推广，dp[i][j] 共 2k + 1 种状态，奇数为持有、偶数为不持有
 *
 * 复杂度：时间复杂度 O(nk)，空间复杂度 O(nk)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0188-best-time-to-buy-and-sell-stock-iv.html
 *
 * 相关题目推荐：
 *   TODO 压缩
 *   121. 买卖股票的最佳时机
 *   122. 买卖股票的最佳时机 II
 *   123. 买卖股票的最佳时机 III
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(2 * k + 1));
        // 不要想啥dp.size.size（大错特错，应该是dp[0].size），不就是2k嘛，不用<=，因为2k肯定是偶数:D，注意+=2
        for (int i = 1; i < 2 * k; i += 2) {
            dp[0][i] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            // 是不是<=，自己可以举个例子k=2，注意+=2
            // 以不操作为起点，后面的不持有和持有第一次股票，都依赖它，所以要向后两个状态，下一轮循环再向后而不会处理当前状态
            for (int j = 0; j < 2 * k; j += 2) {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> prices1 = {2, 4, 1};
    cout << solution.maxProfit(2, prices1) << endl; // 期望输出 2

    // 示例 2
    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    cout << solution.maxProfit(2, prices2) << endl; // 期望输出 7

    return 0;
}
