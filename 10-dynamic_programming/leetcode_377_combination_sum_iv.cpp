/**
 * LeetCode 377. 组合总和 Ⅳ
 * https://leetcode.cn/problems/combination-sum-iv/
 *
 * 题目：给你一个由不同整数组成的数组 nums 和一个目标整数 target。请你从 nums
 *       中找出并返回总和为 target 的元素组合的个数。顺序不同的序列被视作不同的
 *       组合（即排列数）。
 *
 * 思路：完全背包求排列数，外层遍历容量、内层遍历物品，dp[j] += dp[j - nums[i]]
 *
 * 复杂度：时间复杂度 O(mn)，空间复杂度 O(n)（m为硬币种数，n为总金额）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0377-combination-sum-iv.html
 *
 * 相关题目推荐：
 *   322. 零钱兑换
 *   518. 零钱兑换 II
 *   39. 组合总和
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<unsigned long long> dp(target + 1);
        dp[0] = 1;
        // 先容量求排列，这题有个陷阱，就是题目说的是求组合个数，但不是数学的组合数
        for (int j = 1; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= j) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 2, 3};
    cout << solution.combinationSum4(nums1, 4) << endl; // 期望输出 7

    // 示例 2
    vector<int> nums2 = {9};
    cout << solution.combinationSum4(nums2, 3) << endl; // 期望输出 0

    return 0;
}
