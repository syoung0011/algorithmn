/**
 * LeetCode 343. 整数拆分
 * https://leetcode.cn/problems/integer-break/
 *
 * 题目：给定一个正整数 n，将其拆分为 k 个正整数的和（k >= 2），并使这些整数的
 *       乘积最大化。返回你可以获得的最大乘积。
 *
 * 思路：动态规划，dp[i] = max(j * (i-j), j * dp[i-j])，j 从 1 到 i-1 遍历
 *
 * 复杂度：时间复杂度 O(n^2)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0343-integer-break.html
 *
 * 相关题目推荐：
 *   279. 完全平方数
 *   650. 只有两个键的键盘
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[1] = 0;
        // 需警惕n = 1，此时下面赋值越界，所以需要提前返回
        if (n == 1) return 0;
        // 初始化要到2，不然dp[1]=0你咋弄都还是0，而且dp[1] dp[0]其实没用
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            // 遍历到一半就行，对称思维，极致压缩性能
            for (int j = 1; j <= i >> 1; j++) {
                // 不用重载max，直接写两句比较三元
                dp[i] = max(dp[i], j * (i - j));
                dp[i] = max(dp[i], j * dp[i - j]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.integerBreak(2) << endl; // 期望输出 1（1 + 1 = 2, 1 x 1 = 1）

    // 示例 2
    cout << solution.integerBreak(10) << endl; // 期望输出 36（3 x 3 x 4 = 36）

    return 0;
}
