/**
 * LeetCode 53. 最大子数组和
 * https://leetcode.cn/problems/maximum-subarray/
 *
 * 题目：给定整数数组 nums，返回所有非空连续子数组中的最大和。
 *
 * 思路：dp[i] 表示以 nums[i] 结尾的最大连续子数组和。
 *       从左往右遍历，在延长上一段与从 nums[i] 开始新一段之间取较大值。
 *       子数组可以在任意位置结束，因此答案是所有 dp[i] 中的最大值。
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0053-maximum-subarray-dynamic-programming.html
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray(nums1) << endl;  // 期望输出 6

    vector<int> nums2 = {1};
    cout << solution.maxSubArray(nums2) << endl;  // 期望输出 1

    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << solution.maxSubArray(nums3) << endl;  // 期望输出 23

    vector<int> nums4 = {-8, -3, -5};
    cout << solution.maxSubArray(nums4) << endl;  // 期望输出 -3

    return 0;
}
