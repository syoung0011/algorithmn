/**
 * LeetCode 198. 打家劫舍
 * https://leetcode.cn/problems/house-robber/
 *
 * 题目：你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你
 *       偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋
 *       在同一晚上被小偷闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负
 *       整数数组，计算你不触动警报装置的情况下，一夜之内能够偷窃到的最高金额。
 *
 * 思路：dp[i] 表示偷到第 i 间房屋时的最高金额，dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)，若用双变量滚动的空间可降到 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0198-house-robber.html
 *
 * 相关题目推荐：
 *   TODO 双变量滚动
 *   213. 打家劫舍 II
 *   337. 打家劫舍 III
 *   740. 删除并获得点数
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        // 非法输入别忘了
        if (nums.empty()) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if (nums.size() > 1) dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            // 动态规划的正确性在于它不是某一瞬间的快照，而是某一过程的瞬间，它依赖于前面所有状态，这是最核心的
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << solution.rob(nums1) << endl; // 期望输出 4

    // 示例 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << solution.rob(nums2) << endl; // 期望输出 12

    return 0;
}
