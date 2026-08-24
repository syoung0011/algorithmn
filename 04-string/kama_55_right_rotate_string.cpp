/**
 * 卡码网 55. 右旋字符串（第八期模拟笔试）（ACM 模式）
 * https://kamacoder.com/
 *
 * 题目：字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。
 *       给定一个字符串 s 和一个正整数 k，将字符串中后面 k 个字符移到字符串的前面，
 *       实现字符串的右旋转操作。例如 "abcdefg" + k=2 转换为 "fgabcde"。
 *
 * 输入：共两行。第一行为正整数 k，代表右旋转的位数；第二行为字符串 s
 *       （数据范围 1 <= k < 10000，1 <= s.length < 10000）。
 *
 * 思路：提升难度：不能申请额外空间，只能在本串上操作。
 *       先整体反转，此时尾部 k 个字符跑到了前面、前部跑到了后面，
 *       两段子串的顺序已交换，只是段内字符顺序是反的；
 *       再把两段子串各自局部反转，负负得正，恢复段内字符顺序
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)（原地反转，不计字符串本身存储）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/string/kamacoder-0055-right-rotate-string.html
 *
 * 相关题目推荐：
 *   剑指 Offer 58 - II. 左旋转字符串
 *   344. 反转字符串
 *   151. 反转字符串中的单词
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverseStr(string &s, int left, int right) {
    for (; left < right; left++, right--) {
        swap(s[left], s[right]);
    }
}

int main() {
    int k;
    string s;
    while (cin >> k >> s) {
        // 这里最好用库函数了，因为0,k天然左闭右开
        reverseStr(s, 0, s.size() - 1);
        // 反转后就是0,k-1了而不是size-k-1
        reverseStr(s, 0, k - 1);
        reverseStr(s, k, s.size() - 1);
        // 写在循环体内
        cout << s << endl; // 最好endl，不然上轮输出和下轮输入可能在一行
    }
    return 0;
}
