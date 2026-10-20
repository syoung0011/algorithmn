/**
 * LeetCode 1049. 最后一块石头的重量 II
 * https://leetcode.cn/problems/last-stone-weight-ii/
 *
 * 题目：有一堆石头，用整数数组 stones 表示。每次可以选择两块石头碰撞，碰撞规则：
 *       如果重量 x == y，两块石头都会被完全粉碎；如果 x != y，重量为 x 和 y 的
 *       石头碰撞后，重量为 abs(x - y) 的石头会保留下来。最后最多只会剩下一块
 *       石头，返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
 *
 * 思路：01 背包，把石头分成两堆重量尽量接近，容量为sum/2，答案为 sum - 2 * dp[sum/2]
 *
 * 复杂度：时间复杂度 O(mn)，空间复杂度 O(n)（其中 m 为石头块数，n 为总重量的一半）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/1049-last-stone-weight-ii.html
 *
 * 相关题目推荐：
 *   416. 分割等和子集
 *   494. 目标和
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        // 本题难点在于01背包模型以及题意的翻译转化，直接变成两组石头之差，这里暂时不是很理解如何转化来的
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int n = sum >> 1;
        vector<int> dp(n + 1);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = n; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        // sum - dp[n] 是另一份，一定大于等于背包价值，因为n向下取整，容量不对称
        return sum - 2 * dp[n];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    cout << solution.lastStoneWeightII(stones1) << endl; // 期望输出 1

    // 示例 2
    vector<int> stones2 = {31, 26, 33, 21, 40};
    cout << solution.lastStoneWeightII(stones2) << endl; // 期望输出 5

    return 0;
}
