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
 * 复杂度：时间复杂度 O(3^4) = O(1)（IP 固定 4 段、每段最多 3 种长度，
 *        切分组合数为常数 3^4 = 81；每段合法性判断 O(1)。
 *        注意别写成 O(3^n)：段数固定为 4，不是变量）
 *        空间复杂度 O(n)（按值传入的字符串副本；递归栈固定 4 层 O(1)，
 *        结果至多 81 个定长串 O(1)）
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

// 用小数点的个数来判断合法性，比较巧妙，很难想到
int pointSum;
vector<string> res;

class Solution {
public:
    // 本题难点和精髓就在于如何抽出，以及怎么实现判断函数
    bool isValid(const string &s, int left, int right) {
        if (left > right) return false;
        if (s[left] == '0' && left != right) return false;
        int num = 0;
        for (int i = left; i <= right; i++) {
            num = num * 10 + (s[i] - '0');
            // 在里面判断是个好习惯，就近原则不易忘，还能防止溢出
            if (num > 255) {
                return false;
            }
        }
        return true;
    }

    // 不能const string &s，那样没法修改
    // 本题是原地思路，要是用path应该也可以，选择要灵活
    void dfs(string &s, int index) {
        if (pointSum == 3) {
            if (isValid(s, index, s.size() - 1)) {
                res.push_back(s);
                return;
            }
        }
        // 在索引元素后面分割
        for (int i = index; i < s.size(); i++) {
            if (isValid(s, index, i)) {
                pointSum++;
                s.insert(s.begin() + i + 1, '.');
                // 隐藏坑，插入.后，目标位置后移，需要再+1
                dfs(s, i + 2);
                pointSum--;
                s.erase(s.begin() + i + 1);
            } else break;   // 剪枝别忘了
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
