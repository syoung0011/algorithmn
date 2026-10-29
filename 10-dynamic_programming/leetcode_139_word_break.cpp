/**
 * LeetCode 139. 单词拆分
 * https://leetcode.cn/problems/word-break/
 *
 * 题目：给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用
 *       字典中出现的单词拼接出 s。注意：不要求字典中出现的单词全部都使用，并且字典
 *       中的单词可以重复使用。
 *
 * 思路：完全背包求排列可行性，dp[j] 表示长度为 j 的前缀是否能被字典中的单词拆分
 *
 * 复杂度：时间复杂度 O(n^3)（双层 n² × substr 拷贝 O(n)），空间复杂度 O(n)（n为字符串长度）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/0139-word-break.html
 *
 * 相关题目推荐：
 *   140. 单词拆分 II
 *   377. 组合总和 Ⅳ
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        // 集合才有find，大大简化算法
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        // 非正规物品，或抽象物品，这里i不是物品下标，而是容量的下标，通过运算间接(j - i，这个要画个图就看出来了，牛)表示物品，非常关键
        for (int j = 1; j <= s.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (wordSet.find(s.substr(i, j - i)) != wordSet.end()) {
                    dp[j] = dp[j] || dp[i]; // 也可融合到if，为 && dp[i] == true
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    Solution solution;

    // 示例 1
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << solution.wordBreak(s1, wordDict1) << endl; // 期望输出 1（true）

    // 示例 2
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << solution.wordBreak(s2, wordDict2) << endl; // 期望输出 1（true）

    // 示例 3
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << solution.wordBreak(s3, wordDict3) << endl; // 期望输出 0（false）

    return 0;
}
