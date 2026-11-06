/**
 * LeetCode 309. 买卖股票的最佳时机含冷冻期
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 *
 * 题目：给定一个整数数组 prices，其中第 prices[i] 表示第 i 天的股票价格。设计一个
 *       算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易
 *       （多次买卖一支股票）：卖出股票后，你无法在第二天买入股票（即冷冻期为 1 天）。
 *
 * 思路：dp[i][j] 四种状态——持有、不持有（非冷冻）、冷冻、不持有（当天卖出）
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0309-best-time-to-buy-and-sell-stock-with-cooldown.html
 *
 * 相关题目推荐：
 *   122. 买卖股票的最佳时机 II
 *   714. 买卖股票的最佳时机含手续费
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // 持股， 保持卖出。 当天卖出， 冷冻期
        // 本次dp含义是难点，没有买入状态和不操作状态，冷冻状态用于表现间隔，保持卖出也是精髓
        vector<vector<int> > dp(prices.size(), vector<int>(4));
        dp[0][0] = -prices[0];
        // 其余初始化为0，因为都是违规，所以从递推公式来推初始值，也可以像之前考虑当天买当天卖
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        // 不一定就是dp[prices.size() - 1][1]，因为最终策略完全不同
        return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> prices1 = {1, 2, 3, 0, 2};
    cout << solution.maxProfit(prices1) << endl; // 期望输出 3

    // 示例 2
    vector<int> prices2 = {1};
    cout << solution.maxProfit(prices2) << endl; // 期望输出 0

    return 0;
}
