/**
 * LeetCode 509. 斐波那契数
 * https://leetcode.cn/problems/fibonacci-number/
 *
 * 题目：斐波那契数（通常用 F(n) 表示）形成的序列称为斐波那契数列。该数列由 0 和
 *       1 开始，后面的每一项数字都是前面两项数字的和。给定 n，请计算 F(n)。
 *
 * 思路：动态规划，dp[i] = dp[i-1] + dp[i-2]，可用滚动变量优化空间
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0509-fibonacci-number.html
 *
 * 相关题目推荐：
 *   70. 爬楼梯
 *   746. 使用最小花费爬楼梯
 *   1137. 第 N 个泰波那契数
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            // 也可让 tmp = a+b
            int tmp = b;
            b = a + b;
            a = tmp;
        }
        return b;
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.fib(2) << endl;  // 期望输出 1

    // 示例 2
    cout << solution.fib(3) << endl;  // 期望输出 2

    // 示例 3
    cout << solution.fib(4) << endl;  // 期望输出 3

    return 0;
}
