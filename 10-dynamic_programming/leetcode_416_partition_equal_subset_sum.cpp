/**
 * LeetCode 416. 分割等和子集
 * https://leetcode.cn/problems/partition-equal-subset-sum/
 *
 * 题目：给你一个只包含正整数的非空数组 nums。请你判断是否可以将这个数组分割成
 *       两个子集，使得两个子集的元素和相等。
 *
 * 思路：01 背包，容量为 sum/2，dp[j] 表示容量 j 能装下
 *      的最大价值，判断 dp[target] == target；注意 sum 为奇数直接返回 false
 *
 * 复杂度：时间复杂度 O(mn)，空间复杂度 O(n)（其中 m 为数组大小，n 为总和的一半）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0416-partition-equal-subset-sum.html
 *
 * 相关题目推荐：
 *   1049. 最后一块石头的重量 II
 *   494. 目标和
 *   474. 一和零
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        // 这题最难的就是想到和01背包的关联
        // 之所以算法能成功，就是建立在01背包的最大价值的正确性，给定容量结果就是最大价值，而不是贪心那样不一定最大价值
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum & 0x1) return false;
        int n = sum >> 1;
        vector<int> dp(n + 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = n; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        // 但也不一定能装到
        return dp[n] == n;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 5, 11, 5};
    cout << (solution.canPartition(nums1) ? "true" : "false") << endl; // 期望输出 true

    // 示例 2
    vector<int> nums2 = {1, 2, 3, 5};
    cout << (solution.canPartition(nums2) ? "true" : "false") << endl; // 期望输出 false

    return 0;
}
