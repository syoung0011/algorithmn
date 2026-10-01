/**
 * LeetCode 122. 买卖股票的最佳时机 II
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 *
 * 题目：给你一个整数数组 prices，其中 prices[i] 表示某支股票第 i 天的价格。
 *       在每一天，你可以决定是否购买和/或出售股票。你在任何时候最多只能持有
 *       一股股票。你也可以先购买，然后在同一天出售。返回你能获得的最大利润。
 *
 * 思路：贪心，只收集每天的正利润（后一天减当天），累加即为最大利润
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0122-best-time-to-buy-and-sell-stock-ii.html
 *
 * 相关题目推荐：
 *   121. 买卖股票的最佳时机
 *   123. 买卖股票的最佳时机 III
 *   309. 最佳买卖股票时机含冷冻期
 *   714. 买卖股票的最佳时机含手续费
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 贪心，太神了，这个题必须得记住，不用复杂的模型算法，只是差值累加，而差值的意义只要会意不用言传，也描述不清
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int res = 0;
        // 根据情况来，这里差值我就觉得i = 1比i = 0好
        for (int i = 1; i < prices.size(); i++) {
            int num = prices[i] - prices[i - 1];
            res += max(num, 0);
        }
        return res;
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
