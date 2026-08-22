/**
 * LeetCode 344. 反转字符串
 * https://leetcode.cn/problems/reverse-string/
 *
 * 题目：编写一个函数，其作用是将输入的字符串反转过来。必须原地修改输入数组，
 *       使用 O(1) 的额外空间解决这一问题。
 *
 * 思路：双指针，左右字符交换并向中间移动
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/string/0344-reverse-string.html
 *
 * 相关题目推荐：
 *   541. 反转字符串 II
 *   151. 反转字符串中的单词
 *   345. 反转字符串中的元音字母
 */

#include <iostream>
#include <vector>
#include <algorithm> // 显示包含swap

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            // swap(s[left],s[right]); // 也可直接用库函数
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            // 容易忘记改变循环变量，尤其是while
            left++;
            right--;
        }
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    solution.reverseString(s1);
    for (char c: s1) {
        cout << c; // 期望输出 olleh
    }
    cout << endl;

    // 示例 2
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    solution.reverseString(s2);
    for (char c: s2) {
        cout << c; // 期望输出 hannaH
    }
    cout << endl;

    return 0;
}
