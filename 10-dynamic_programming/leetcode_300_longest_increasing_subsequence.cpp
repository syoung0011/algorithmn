/**
 * LeetCode 300. 最长递增子序列
 * https://leetcode.cn/problems/longest-increasing-subsequence/
 *
 * 题目：给你一个整数数组 nums，找到其中最长严格递增子序列的长度。子序列是由数组派生
 *       而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，
 *       [3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 *
 * 思路：dp[i] 表示以 nums[i] 结尾的最长递增子序列长度，dp[i] = max(dp[j] + 1)（nums[j] < nums[i]）
 *
 * 复杂度：时间复杂度 O(n^2)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0300-longest-increasing-subsequence.html
 *
 * 相关题目推荐：
 *   674. 最长连续递增序列
 *   718. 最长重复子数组
 *   354. 俄罗斯套娃信封问题
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        // 完善点可以初始化认真点，这里直接让res 1了
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            // 找最大其实本质是，但是手写O(n)一般够用了
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                // 注意别把result放在内循环
            }
            result = max(result, dp[i]); // res的位置!!!
        }
        return result;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << solution.lengthOfLIS(nums1) << endl; // 期望输出 4

    // 示例 2
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << solution.lengthOfLIS(nums2) << endl; // 期望输出 4

    // 示例 3
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << solution.lengthOfLIS(nums3) << endl; // 期望输出 1

    return 0;
}
