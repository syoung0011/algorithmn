/**
 * LeetCode 376. 摆动序列
 * https://leetcode.cn/problems/wiggle-subsequence/
 *
 * 题目：如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。
 *       给定一个整数数组 nums，返回 nums 中作为摆动序列的最长子序列的长度。
 *
 * 思路：贪心，统计峰谷转折点数量，去掉单调区间中间的元素
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0376-wiggle-subsequence.html
 *
 * 相关题目推荐：
 *   TODO DP版本
 *   53. 最大子数组和
 *   122. 买卖股票的最佳时机 II
 *   300. 最长递增子序列
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int preDiff = 0;
        int curDiff = 0;
        // 也可用if (nums.size() <= 1) return nums.size(); 放于开头，还是融合的if
        int res = !nums.empty();
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            // 本题要分为三种情形，具体见官网，下面的if完全包含了这些情况，pre初始为0也是恰到好处
            if (preDiff <= 0 && curDiff > 0
                || preDiff >= 0 && curDiff < 0) {
                res++;
                // 放在里面，满足再变更
                preDiff = curDiff;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 7, 4, 9, 2, 5};
    cout << solution.wiggleMaxLength(nums1) << endl; // 期望输出 6

    // 示例 2
    vector<int> nums2 = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << solution.wiggleMaxLength(nums2) << endl; // 期望输出 7

    // 示例 3
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << solution.wiggleMaxLength(nums3) << endl; // 期望输出 2

    return 0;
}
