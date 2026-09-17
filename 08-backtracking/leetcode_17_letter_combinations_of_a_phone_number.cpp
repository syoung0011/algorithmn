/**
 * LeetCode 17. 电话号码的字母组合
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
 *
 * 题目：给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以
 *       按任意顺序返回。数字到字母的映射与电话按键相同（如 2 -> "abc"）。
 *
 * 思路：回溯法，数字映射字符串数组，逐位递归收集字母
 *
 * 复杂度：时间复杂度 O(a^size)，空间复杂度 O(sie)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0017-letter-combinations-of-a-phone-number.html
 *
 * 相关题目推荐：
 *   77. 组合
 *   39. 组合总和
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 没必要用二维vector，灵活点
// 合法下标2-9
const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};

vector<string> res;
string path;

class Solution {
public:
    void dfs(string digits, int idx) {
        if (idx == digits.size()) {
            res.push_back(path);
            return;
        }
        int digit = digits[idx] - '0';
        for (int i = 0; i < letterMap[digit].size(); i++) {
            path.push_back(letterMap[digit][i]);
            dfs(digits, idx + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        res.clear();
        path.clear();
        dfs(digits, 0);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    for (const string &s: solution.letterCombinations("23")) {
        cout << s << " "; // 期望输出 ad ae af bd be bf cd ce cf
    }
    cout << endl;

    // 示例 2
    for (const string &s: solution.letterCombinations("")) {
        cout << s << " "; // 期望输出为空
    }
    cout << endl;

    // 示例 3
    for (const string &s: solution.letterCombinations("2")) {
        cout << s << " "; // 期望输出 a b c
    }
    cout << endl;

    return 0;
}
