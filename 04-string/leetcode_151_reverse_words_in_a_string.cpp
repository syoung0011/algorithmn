/**
 * LeetCode 151. 翻转字符串里的单词
 * https://leetcode.cn/problems/reverse-words-in-a-string/
 *
 * 题目：给你一个字符串 s，请你反转字符串中单词的顺序。单词是由非空格字符组成的
 *       字符串。s 中使用至少一个空格将字符串中的单词分隔开。
 *       返回单词顺序颠倒且单词之间用单个空格连接的结果字符串，首尾无多余空格。
 *
 * 思路：先移除多余空格，再整体反转，最后逐个单词反转
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度: O(1) 或 O(n)，取决于语言中字符串是否可变
 *
 * 参考：代码随想录 https://programmercarl.com/algo/string/0151-reverse-words-in-a-string.html
 *
 * 相关题目推荐：
 *   344. 反转字符串
 *   541. 反转字符串 II
 *   557. 反转字符串中的单词 III
 */

#include <iostream>
#include <string>
#include <algorithm> // 显示包含swap

using namespace std;

class Solution {
public:
    // 自写翻转函数，因为这里左闭右闭更方便。注意命名最好不要和库函数同名
    void reverseStr(string &s, int slow, int fast) {
        while (slow < fast) {
            swap(s[slow], s[fast]);
            slow++;
            fast--; // 别写成fast++
        }
    }

    void removeExtraSpaces(string &s) {
        // 快指针可放到循环内定义
        int slow = 0;

        // 方案1：引入额外标记位，命名是一层选择，删除逻辑又是一层选择，应该是空格->字母这个时机插入空格
        bool isWhite = false;
        // 开头不添加空格，可以多设置个标记位（逻辑繁琐），也可用方案1.2，用slow==0天生标记位

        // 方案1.1
        bool no_copy_flag = true;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != ' ') {
                if (no_copy_flag) {
                    no_copy_flag = false;
                } else if (isWhite) {
                    s[slow++] = ' ';
                }
                isWhite = false;
                s[slow++] = s[fast];
            } else {
                isWhite = true;
            }
        }

        // 方案1.2
        // for (int fast=0;fast<s.size();fast++) {
        //     if (s[fast]!=' ') {
        //         if (slow!=0&&isWhite) {
        //             s[slow++]=' ';
        //         }
        //         isWhite=false;
        //         s[slow++]=s[fast];
        //     }
        //     else {
        //         isWhite=true;
        //     }
        // }

        // 方案2：不用标记位，在循环体内套循环反转单词（复杂度不是n^2，因为语句执行总数仍然是n，也就是fast从0线性增长到n）
        // for (int fast = 0; fast < s.size(); ++fast) {
        //     if (s[fast] != ' ') {
        //         if (slow != 0) s[slow++] = ' ';
        //         while (fast < s.size() && s[fast] != ' ') {
        //             s[slow++] = s[fast++];
        //         }
        //     }
        // }

        // 在这里更新大小，因为外部slow丢失无法确定大小
        // 而且去除空格本就包括大小的减少
        s.resize(slow); // 不是slow+1，因为已经slow++
    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverseStr(s, 0, s.size() - 1);
        int slow = 0;

        // 写法一：较为繁琐，fast自增写进循环体
        for (int fast = 0; fast < s.size();) {
            fast++;
            // 条件顺序必须这样
            if (fast == s.size() || s[fast] == ' ') {
                reverseStr(s, slow, fast - 1);
                slow = fast + 1;
                // 无需fast=slow，因为下轮循环fast++就跟上了
            }
        }

        // 写法二：最标准for，融合字符串边界情况
        // // <=
        // for (int fast=0;fast<=s.size();fast++) {
        //     if (fast==s.size()||s[fast]==' ') {
        //         reverse(s,slow,fast-1);
        //         slow=fast+1;
        //         // 无需fast=slow，因为下轮循环fast++就跟上了
        //     }
        // }

        return s;
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.reverseWords("the sky is blue") << endl; // 期望输出 blue is sky the

    // 示例 2
    cout << solution.reverseWords("  hello world  ") << endl; // 期望输出 world hello

    // 示例 3
    cout << solution.reverseWords("a good   example") << endl; // 期望输出 example good a

    return 0;
}
