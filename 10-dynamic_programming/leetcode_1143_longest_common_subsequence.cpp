/**
 * LeetCode 1143. 最长公共子序列
 * https://leetcode.cn/problems/longest-common-subsequence/
 *
 * 题目：给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
 *       如果不存在公共子序列，返回 0。一个字符串的子序列是指这样一个新的字符串：
 *       它由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何
 *       字符）后组成的新字符串。
 *
 * 思路：dp[i][j] 表示 text1[0..i-1] 与 text2[0..j-1] 的最长公共子序列长度，相等加一，否则取两侧较大值
 *
 * 复杂度：时间复杂度 O(mn)，空间复杂度 O(mn)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/1143-longest-common-subsequence.html
 *
 * 相关题目推荐：
 *   718. 最长重复子数组
 *   1035. 不相交的线
 *   583. 两个字符串的删除操作
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp依旧与718题一样含义
        vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 有点kmp味道了，这是最难点
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        // 这里不用和718那题一样max。因为状态连续向后传导，以。。。结尾并不代表真的结尾
        return dp[text1.size()][text2.size()];
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.longestCommonSubsequence("abcde", "ace") << endl; // 期望输出 3

    // 示例 2
    cout << solution.longestCommonSubsequence("abc", "abc") << endl; // 期望输出 3

    // 示例 3
    cout << solution.longestCommonSubsequence("abc", "def") << endl; // 期望输出 0

    return 0;
}
