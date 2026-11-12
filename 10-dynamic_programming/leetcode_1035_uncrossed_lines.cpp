/**
 * LeetCode 1035. 不相交的线
 * https://leetcode.cn/problems/uncrossed-lines/
 *
 * 题目：在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。现在，可以
 *       绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足：
 *       nums1[i] == nums2[j]，且绘制的直线不与任何其他连线（非水平线）相交。请你
 *       计算绘制的最大连线数，并返回最大连线数。
 *
 * 思路：本质是求最长公共子序列，dp[i][j] 与 1143 题同构
 *
 * 复杂度：时间复杂度 O(mn)，空间复杂度 O(mn)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/1035-uncrossed-lines.html
 *
 * 相关题目推荐：
 *   1143. 最长公共子序列
 *   718. 最长重复子数组
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int> > dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1_1 = {1, 4, 2};
    vector<int> nums1_2 = {1, 2, 4};
    cout << solution.maxUncrossedLines(nums1_1, nums1_2) << endl; // 期望输出 2

    // 示例 2
    vector<int> nums2_1 = {2, 5, 1, 2, 5};
    vector<int> nums2_2 = {10, 5, 2, 1, 5, 2};
    cout << solution.maxUncrossedLines(nums2_1, nums2_2) << endl; // 期望输出 3

    // 示例 3
    vector<int> nums3_1 = {1, 3, 7, 1, 7, 5};
    vector<int> nums3_2 = {1, 9, 2, 5, 1};
    cout << solution.maxUncrossedLines(nums3_1, nums3_2) << endl; // 期望输出 2

    return 0;
}
