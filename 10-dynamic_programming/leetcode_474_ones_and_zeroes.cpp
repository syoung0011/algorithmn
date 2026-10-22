/**
 * LeetCode 474. 一和零
 * https://leetcode.cn/problems/ones-and-zeroes/
 *
 * 题目：给你一个二进制字符串数组 strs 和两个整数 m 和 n。请你找出并返回 strs
 *       的最大子集的大小，该子集中最多有 m 个 0 和 n 个 1。如果 x 的所有元素
 *       也是 y 的元素，集合 x 是集合 y 的子集。
 *
 * 思路：01 背包二维费用，dp[i][j] 表示最多 i 个 0 和 j 个 1 时子集的最大长度
 *
 * 复杂度：时间复杂度 O(kmn)（统计字符另需 Σ|s|，通常可忽略），空间复杂度 O(mn)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0474-ones-and-zeroes.html
 *
 * 相关题目推荐：
 *   416. 分割等和子集
 *   494. 目标和
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 二维背包，有两个容量维度而已，实际还是一维dp的模板
    int findMaxForm(vector<string> &strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        // 对于字符串类型的数组，可以直接用for str: strs这个更简洁
        for (int i = 0; i < strs.size(); i++) {
            // 别写成int a, b = 0，这样a没初始化，运行出错
            int c0 = 0, c1 = 0;
            for (int l = 0; l < strs[i].size(); l++) {
                if (strs[i][l] == '0') {
                    c0++;
                } else {
                    c1++;
                }
            }
            for (int j = m; j >= c0; j--) {
                for (int k = n; k >= c1; k--) {
                    // 必须倒序，倒序就可以让判断融入for的循环条件
                    dp[j][k] = max(dp[j - c0][k - c1] + 1, dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<string> strs1 = {"10", "0001", "111001", "1", "0"};
    cout << solution.findMaxForm(strs1, 5, 3) << endl; // 期望输出 4

    // 示例 2
    vector<string> strs2 = {"10", "0", "1"};
    cout << solution.findMaxForm(strs2, 1, 1) << endl; // 期望输出 2

    return 0;
}
