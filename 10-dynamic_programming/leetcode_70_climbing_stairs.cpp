/**
 * LeetCode 70. 爬楼梯
 * https://leetcode.cn/problems/climbing-stairs/
 *
 * 题目：假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。
 *       你有多少种不同的方法可以爬到楼顶呢？
 *
 * 思路：动态规划，dp[i] = dp[i-1] + dp[i-2]，本质为斐波那契
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0070-climbing-stairs.html
 *
 * 相关题目推荐：
 *   746. 使用最小花费爬楼梯
 *   509. 斐波那契数
 *   377. 组合总和 Ⅳ
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 变量法
        // int a = 1, b = 1;
        // // 省去if，因为都是返回1，和斐波那契不同，且n = 0非法值，也和fb不同
        // for (int i = 2; i <= n; i++) {
        //     int tmp = a + b;
        //     a = b;
        //     b = tmp;
        // }
        // return b;

        // 数组法
        // 注意要指定大小后才能赋值，比如dp[1]，且大小为n+1，以为循环到n
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        // 也可dp[n]
        return dp.back();
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.climbStairs(2) << endl;  // 期望输出 2

    // 示例 2
    cout << solution.climbStairs(3) << endl;  // 期望输出 3

    return 0;
}
