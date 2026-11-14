/**
 * LeetCode 392. 判断子序列
 * https://leetcode.cn/problems/is-subsequence/
 *
 * 题目：给定字符串 s 和 t，判断 s 是否为 t 的子序列。字符串的一个子序列是原始字符串
 *       删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，
 *       "ace" 是 "abcde" 的一个子序列，而 "aec" 不是）。
 *
 * 思路：dp[i][j] 表示 s[0..i-1] 与 t[0..j-1] 的最长公共子序列长度，按子序列定义可简化为
 *       只对 t 做删除（不能删 s），因此等价于求最长公共子序列，最后判断是否等于 s.size()。
 *       转移：s[i-1] == t[j-1] 时 dp[i][j] = dp[i-1][j-1] + 1；否则 dp[i][j] = dp[i][j-1]
 *       （只允许删 t 的字符，所以不是 dp[i-1][j]）。
 *       与之等价的贪心双指针写法更优：i 指向 s，遍历 t，字符相同则 i++，最后看 i 是否走完 s。
 *
 * 复杂度：时间复杂度 O(n * m)，空间复杂度 O(n * m)（贪心双指针为 O(1)）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0392-is-subsequence.html
 *
 * 相关题目推荐：
 *   115. 不同的子序列
 *   524. 通过删除字母匹配到字典里最长单词
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 动态规划：等价于求 s 与 t 的最长公共子序列，长度等于 s.size() 即为子序列
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 只允许删除 t 的字符，因此从左侧格转移
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[n][m] == n;
    }

    // 贪心双指针：i 指向 s，遍历 t，字符相同时 i 前进，最后看 s 是否被完整匹配
    bool isSubsequenceTwoPointers(string s, string t) {
        int i = 0;
        for (int j = 0; j < static_cast<int>(t.size()) && i < static_cast<int>(s.size()); j++) {
            if (s[i] == t[j]) {
                i++;
            }
        }
        return i == static_cast<int>(s.size());
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.isSubsequence("abc", "ahbgdc") << endl;  // 期望输出 1（true）

    // 示例 2
    cout << solution.isSubsequence("axc", "ahbgdc") << endl;  // 期望输出 0（false）

    // 边界：s 为空
    cout << solution.isSubsequence("", "ahbgdc") << endl;  // 期望输出 1（true）

    // 双指针写法对照
    cout << solution.isSubsequenceTwoPointers("abc", "ahbgdc") << endl;  // 期望输出 1
    cout << solution.isSubsequenceTwoPointers("axc", "ahbgdc") << endl;  // 期望输出 0

    return 0;
}
