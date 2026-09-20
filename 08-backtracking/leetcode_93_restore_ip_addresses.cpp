/**
 * LeetCode 93. 复原 IP 地址
 * https://leetcode.cn/problems/restore-ip-addresses/
 *
 * 题目：有效 IP 地址正好由四个整数（每个位于 0 到 255 之间，且不能含有前导 0）
 *       组成。给定一个只包含数字的字符串 s，用以表示一个 IP 地址，返回所有可能
 *       的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
 *
 * 思路：回溯法，插入三个点，每段校验 0-255 且无前导零
 *
 * 复杂度：时间复杂度 O(?)，空间复杂度 O(？)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0093-restore-ip-addresses.html
 *
 * 相关题目推荐：
 *   131. 分割回文串
 *   78. 子集
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pointSum;
vector<string> res;

class Solution {
public:
    bool isValid(const string &s, int left, int right) {
        if (left > right) return false;
        if (s[left] == '0' && left != right) return false;
        int num = 0;
        for (int i = left; i <= right; i++) {
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }

    // 直接
    void dfs(string &s, int index) {
        if (pointSum == 3) {
            if (isValid(s, index, s.size() - 1)) {
                res.push_back(s);
                return;
            }
        }
        for (int i = index; i < s.size(); i++) {
            if (isValid(s, index, i)) {
                pointSum++;
                s.insert(s.begin() + i + 1, '.');
                dfs(s, i + 2);
                pointSum--;
                s.erase(s.begin() + i + 1);
            } else break;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        pointSum = 0;
        res.clear();
        dfs(s, 0);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    for (const string &ip: solution.restoreIpAddresses("25525511135")) {
        cout << ip << " "; // 期望输出 255.255.11.135 255.255.111.35
    }
    cout << endl;

    // 示例 2
    for (const string &ip: solution.restoreIpAddresses("0000")) {
        cout << ip << " "; // 期望输出 0.0.0.0
    }
    cout << endl;

    // 示例 3
    for (const string &ip: solution.restoreIpAddresses("101023")) {
        cout << ip << " "; // 期望输出 1.0.10.23 1.0.102.3 10.1.0.23 10.10.2.3 101.0.2.3
    }
    cout << endl;

    return 0;
}
