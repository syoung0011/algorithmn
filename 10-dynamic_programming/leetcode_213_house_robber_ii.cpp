/**
 * LeetCode 213. 打家劫舍 II
 * https://leetcode.cn/problems/house-robber-ii/
 *
 * 题目：你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方
 *       所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻
 *       的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会
 *       自动报警。给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置
 *       的情况下，今晚能够偷窃到的最高金额。
 *
 * 思路：环形拆分为两种情况——不偷首间与不偷尾间，分别做线性打家劫舍后取最大值
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0213-house-robber-ii.html
 *
 * 相关题目推荐：
 *   198. 打家劫舍
 *   337. 打家劫舍 III
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        // 不能从dp[0]的初值出发，这题必须分类讨论取不取第一个，然后转化为两个线性问题，所以可以套用打家劫舍1，直接传参，具体见官网
        // 本方法不太好，相比于官网，等有空再研究
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = dp[0];
        for (int i = 2; i < nums.size() - 1; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        int temp = dp[nums.size() - 2];

        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 0;
        }
        dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return max(temp, dp[nums.size() - 1]);
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {2, 3, 2};
    cout << solution.rob(nums1) << endl;  // 期望输出 3

    // 示例 2
    vector<int> nums2 = {1, 2, 3, 1};
    cout << solution.rob(nums2) << endl;  // 期望输出 4

    // 示例 3
    vector<int> nums3 = {1, 2, 3};
    cout << solution.rob(nums3) << endl;  // 期望输出 3

    return 0;
}
