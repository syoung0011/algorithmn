/**
 * LeetCode 131. 分割回文串
 * https://leetcode.cn/problems/palindrome-partitioning/
 *
 * 题目：给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串。
 *       返回 s 所有可能的分割方案。
 *
 * 思路：回溯法，startIndex 作为切割线，判断子串是否回文，是则加入路径继续切割
 *
 * 复杂度：时间复杂度 O(n · 2^n)
 *        递归树最多 2^(n-1) 种切割方案，每个解需 O(n) 拷贝子串；
 *        本实现另外对每个节点做 O(n) 双指针回文判定，支配项仍是 O(n · 2^n)
 *        空间复杂度 O(n)
 *        path + 递归栈深度。注意：官网写 O(n^2) 是因为其解法用 DP 表 f[n][n]
 *        预处理回文，支配项是那张表；本实现现场判定、无 DP 表，故为 O(n)。
 *        不计输出；计入输出则为 O(n · 2^n)
 *        优化：若改用 O(n^2) DP 预处理回文，回文判定降为 O(1)，
 *        时间变为 O(n^2 + n · 2^n)，空间变为 O(n^2)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0131-palindrome-partitioning.html
 *
 * 相关题目推荐：
 *   93. 复原 IP 地址
 *   78. 子集
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string> > res;
vector<string> path;

class Solution {
public:
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            // 自己做居然忘了，while要注意啊，思维别太跳了
            start++;
            end--;
        }
        return true;
    }

    void dfs(const string &s, int index) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }
        // 相当于在当前下标元素的后面分割
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                string str = s.substr(index, i - index + 1);
                path.push_back(str);
                dfs(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s) {
        res.clear();
        path.clear();
        dfs(s, 0);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    for (const auto &parts: solution.partition("aab")) {
        cout << "[";
        for (size_t i = 0; i < parts.size(); ++i) {
            cout << parts[i] << (i + 1 < parts.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [a,a,b] [aa,b]

    // 示例 2
    for (const auto &parts: solution.partition("a")) {
        cout << "[";
        for (size_t i = 0; i < parts.size(); ++i) {
            cout << parts[i] << (i + 1 < parts.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [a]

    return 0;
}
