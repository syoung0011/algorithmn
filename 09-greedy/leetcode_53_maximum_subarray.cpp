/**
 * LeetCode 53. 最大子数组和
 * https://leetcode.cn/problems/maximum-subarray/
 *
 * 题目：给你一个整数数组 nums，请你找出一个具有最大和的连续子数组（子数组最少
 *       包含一个元素），返回其最大和。
 *
 * 思路：累计和小于 0 时重新开始累计，过程中记录最大值；也可用动态规划
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0053-maximum-subarray.html
 *
 * 相关题目推荐：
 *   152. 乘积最大子数组
 *   918. 环形子数组的最大和
 *   121. 买卖股票的最佳时机
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 官网写法可能更好，从下标0开始
        if (nums.empty()) return 0;
        int sum = nums[0];
        int res= nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum += nums[i]; // 提，不错
            // 注意两个if顺序不能颠倒，其实这种写法还是max最合适，就是两个变量，一个当前最大，一个全局最大
            // 同时注意逻辑，这题还是需要深度思考一下
            if (sum < nums[i]) {
                sum = nums[i];
            }
            if (sum > res) {
                res = sum;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray(nums1) << endl;  // 期望输出 6

    // 示例 2
    vector<int> nums2 = {1};
    cout << solution.maxSubArray(nums2) << endl;  // 期望输出 1

    // 示例 3
    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << solution.maxSubArray(nums3) << endl;  // 期望输出 23

    return 0;
}
