/**
 * LeetCode 674. 最长连续递增序列
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
 *
 * 题目：给定一个未经排序的整数数组，找到最长且连续递增的子序列，并返回该序列的长度。
 *       连续递增的子序列可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，
 *       都有 nums[i] < nums[i + 1]，那么子序列 [nums[l], nums[l + 1], ...,
 *       nums[r - 1], nums[r]] 就是连续递增子序列。
 *
 * 思路：dp[i] 表示以 nums[i] 结尾的最长连续递增序列长度，nums[i] > nums[i - 1] 时 dp[i] = dp[i - 1] + 1
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0674-longest-continuous-increasing-subsequence.html
 *
 * 相关题目推荐：
 *   300. 最长递增子序列
 *   718. 最长重复子数组
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // 看清楚递增子序列还是连续递增子序列，他们要考虑的前状态区间不一样，一个是前面所有，一个是仅仅前一个位置
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
                // 放在外面更好
                res = max(dp[i], res);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 3, 5, 4, 7};
    cout << solution.findLengthOfLCIS(nums1) << endl;  // 期望输出 3

    // 示例 2
    vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << solution.findLengthOfLCIS(nums2) << endl;  // 期望输出 1

    return 0;
}
