/**
 * LeetCode 718. 最长重复子数组
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
 *
 * 题目：给两个整数数组 nums1 和 nums2，返回两个数组中公共的、长度最长的子数组的长度。
 *
 * 思路：dp[i][j] 表示以 nums1[i - 1] 和 nums2[j - 1] 结尾的最长公共子数组长度，相等时 dp[i][j] = dp[i - 1][j - 1] + 1
 *
 * 复杂度：时间复杂度 O(n^m)，空间复杂度 O(n^m)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0718-maximum-length-of-repeated-subarray.html
 *
 * 相关题目推荐：
 *   TODO 状态压缩
 *   1143. 最长公共子序列
 *   300. 最长递增子序列
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int> > dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        // dp[i][j] 表示nums1 以 i - 1，nums2 j - 1为结尾的最大子数组，之所以这样会方便初始化
        // 初始化首先第一行和第一列为0，因为非法，其余也为0，因为无法无条件覆盖，这里没有操作是因为定义已经全初始化0
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1_1 = {1, 2, 3, 2, 1};
    vector<int> nums1_2 = {3, 2, 1, 4, 7};
    cout << solution.findLength(nums1_1, nums1_2) << endl; // 期望输出 3

    // 示例 2
    vector<int> nums2_1 = {0, 0, 0, 0, 0};
    vector<int> nums2_2 = {0, 0, 0, 0, 0};
    cout << solution.findLength(nums2_1, nums2_2) << endl; // 期望输出 5

    return 0;
}
