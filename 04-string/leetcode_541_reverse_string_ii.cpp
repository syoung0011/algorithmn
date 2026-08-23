/**
 * LeetCode 541. 反转字符串 II
 * https://leetcode.cn/problems/reverse-string-ii/
 *
 * 题目：给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，
 *       就反转这 2k 字符中的前 k 个字符。
 *       如果剩余字符少于 k 个，则将剩余字符全部反转；
 *       如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余原样保留。
 *
 * 思路：以 2k 为步长遍历，反转区间起点到 min(i+k, n)
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/string/0541-reverse-string-ii.html
 *
 * 相关题目推荐：
 *   344. 反转字符串
 *   151. 反转字符串中的单词
 */

#include <iostream>
#include <string>
#include <algorithm> // 显示包含swap

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        // 以2k为步长遍历，更加清晰，如果仍然i++，则可能要用计数器来判断累计步长是否等于2k
        for (int i = 0; i < s.size(); i += 2 * k) {
            // i+2*k-1<s.size()||i+2*k-1>=s.size()&&i+k-1<s.size()优化为下面条件，逻辑要清晰
            if (i + k - 1 < s.size()) {
                // 可以抽取成函数，这样不仅能复用反转代码，而且能省去左右指索引变量，简化代码
                int left = i, right = i + k - 1;
                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                continue;
            }
            reverse(s.begin()+i,s.end());
            // continue就是比下面else逻辑上更好，因为这里其实是收尾，也就是最多执行一次，else就不如continue意义清晰
            // else {
            //          // ...
            //     }
            // }
        }
        return s;
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.reverseStr("abcdefg", 2) << endl; // 期望输出 bacdfeg

    // 示例 2
    cout << solution.reverseStr("abcd", 2) << endl; // 期望输出 bacd

    return 0;
}
