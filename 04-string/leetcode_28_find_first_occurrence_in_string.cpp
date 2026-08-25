/**
 * LeetCode 28. 找出字符串中第一个匹配项的下标
 * https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
 *
 * 题目：给你两个字符串 haystack 和 needle，请你在 haystack 字符串中找出
 *       needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle
 *       不是 haystack 的一部分，则返回 -1。
 *
 * 思路：KMP 算法，构建 next 数组后线性匹配
 *
 * 复杂度：时间复杂度 O(n+m)（n 为 haystack 长度，m 为 needle 长度），空间复杂度 O(m)（next 数组）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/string/0028-find-the-index-of-the-first-occurrence-in-a-string.html
 *
 * 相关题目推荐：
 *   459. 重复的子字符串
 *   686. 重复叠加字符串匹配
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 特殊情形
        // 直接用empty不用size
        if (needle.empty()) return 0;
        // next数组也可直接int*
        // 参数二为0，就不用再next[0]=0了
        vector<int> next(needle.size(), 0);
        // 求next数组
        // i为后缀末尾，j为前缀末尾
        int j = 0;
        // TODO 暂时有一点不理解，但原理是根据最长相等前后缀的长度
        for (int i = 1; i < next.size(); i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) j++;
            next[i] = j;
        }
        j = 0; // 复用变量，但表意变为needle的索引
        // i为haystack的索引
        // 自己写的，因与官网方案不同（原生next，即不进行右移或-1），所以没有参照，逻辑可能不完美
        // 核心就是两个串同步比较
        for (int i = 0; i < haystack.size();) {
            if (haystack[i] == needle[j]) {
                j++;
                i++;
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++; // j=0还不能匹配，那就i++，j保持为0
            }
            if (j == needle.size()) {
                return i - j;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.strStr("sadbutsad", "sad") << endl; // 期望输出 0

    // 示例 2
    cout << solution.strStr("leetcode", "leeto") << endl; // 期望输出 -1

    // 示例 3
    cout << solution.strStr("hello", "ll") << endl; // 期望输出 2

    return 0;
}
