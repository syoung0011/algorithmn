/**
 * LeetCode 494. 目标和
 * https://leetcode.cn/problems/target-sum/
 *
 * 题目：给你一个非负整数数组 nums 和一个整数 target。向数组中的每个整数前添加
 *       '+' 或 '-'，然后串联起所有整数，可以构造一个表达式。返回可以通过上述
 *       方法构造的、运算结果等于 target 的不同表达式的数目。
 *
 * 思路：01 背包，设正数和为 x，负数和为 sum-x，
 *      则 x - (sum-x) = target，即 x = (sum+target)/2，求装满容量 x 的方案数
 *
 * 复杂度：时间复杂度 O(mn)，空间复杂度 O(n)（其中，m为元素个数，n为和的一半）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0494-target-sum.html
 *
 * 相关题目推荐：
 *   416. 分割等和子集
 *   1049. 最后一块石头的重量 II
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // 这里我的理解是合二为一了，首先 + 一侧肯定不行，超出sum了，- 一侧另一组会超出sum
        if (abs(target) > sum) return 0;
        // 必须精确等于，因此发生舍入说明不满足
        if ((target + sum) % 2 == 1) return 0;
        // 这里应该最好 sum+target 避免负数算数右移之类出现错误
        int n = sum - target >> 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = n; j >= nums[i]; j--) {
                // 这个递推公式含义以及dp含义和以前完全不同，而且是个难点，需要理解
                // 当容量为 x，当前物品为 y 时，可容纳种数 = 可容纳 x - y 的种数
                // 而且此时一维数组将求和分散到每轮大循环了，其实是 x - i 的种数之和
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 1, 1, 1, 1};
    cout << solution.findTargetSumWays(nums1, 3) << endl;  // 期望输出 5

    // 示例 2
    vector<int> nums2 = {1};
    cout << solution.findTargetSumWays(nums2, 1) << endl;  // 期望输出 1

    return 0;
}
