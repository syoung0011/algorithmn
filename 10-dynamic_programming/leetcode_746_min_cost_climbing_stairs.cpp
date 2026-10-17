/**
 * LeetCode 746. 使用最小花费爬楼梯
 * https://leetcode.cn/problems/min-cost-climbing-stairs/
 *
 * 题目：给你一个整数数组 cost，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付
 *       的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。你可以选择
 *       从下标为 0 或下标为 1 的台阶开始爬楼梯。请你计算并返回达到楼层顶部
 *       的最低花费。
 *
 * 思路：动态规划，dp[i] = min(dp[i-1] + cost[i-1],dp[i-2] + cost[i-2])，爬到第 n 阶的最低花费）
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0746-min-cost-climbing-stairs.html
 *
 * 相关题目推荐：
 *   70. 爬楼梯
 *   509. 斐波那契数
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        // 依然<=，因为要登顶，也就是最后还有一节台阶
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp.back();
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> cost1 = {10, 15, 20};
    cout << solution.minCostClimbingStairs(cost1) << endl;  // 期望输出 15

    // 示例 2
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << solution.minCostClimbingStairs(cost2) << endl;  // 期望输出 6

    return 0;
}
