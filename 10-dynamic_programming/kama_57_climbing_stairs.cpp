/**
 * 卡码网 57. 爬楼梯（完全背包求排列数，ACM 模式）
 * https://kamacoder.com/problempage.php?pid=1067
 *
 * 题目：假设你正在爬楼梯，需要 n 阶才能到达楼顶。每次你可以爬至多 m 个台阶
 *       （1 <= m < n），问有多少种不同的方法可以爬到楼顶。（LeetCode 70 的进阶版，
 *       每次可爬 1~m 阶，LeetCode 上没有对应原题）
 *
 * 输入：一行两个正整数 n、m，分别表示楼顶台阶数与每次最多可爬的台阶数。
 *
 * 输出：一个整数，表示爬到楼顶的方法数。
 *
 * 思路：完全背包求排列数，把 1~m 阶看作重量为 1~m 的物品，n 为背包容量，dp[i] 表示爬到 i 阶的方法数，dp[i] += dp[i - j]；
 *       求排列数需背包容量在外层、物品在内层，内层正序遍历，dp[0] = 1
 *
 * 复杂度：时间复杂度 O(mn)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0070-climbing-stairs-complete-knapsack.html
 *
 * 相关题目推荐：
 *   LeetCode 70. 爬楼梯（基础版，每次固定爬 1 或 2 阶）
 *   LeetCode 377. 组合总和 IV（同样是完全背包求排列数）
 *   LeetCode 518. 零钱兑换 II（对比：完全背包求组合数）
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<unsigned long long> dp(n + 1);
    dp[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (j >= i) {
                dp[j] += dp[j - i];
            }
        }
    }
    // acm要求答案一般都是输出打印，而不是直接return，别犯傻了
    cout << dp[n] << endl;
    return 0;
}
