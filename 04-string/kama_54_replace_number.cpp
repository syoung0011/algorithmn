/**
 * 卡码网 54. 替换数字（第八期模拟笔试）（ACM 模式）
 * https://kamacoder.com/
 *
 * 题目：给定一个字符串 s，它包含小写字母和数字字符，将字符串中的字母字符保持不变，
 *       而将每个数字字符替换为 number。例如 "a1b2c3" 转换为 "anumberbnumbercnumber"。
 *
 * 输入：一个字符串 s，s 仅包含小写字母和数字字符（数据范围 1 <= s.length < 10000）。
 *
 * 思路：先统计数字个数给字符串扩容（每个数字替换成 number 后多占 5 位），
 *       再用双指针从后向前填充，避免从前向后替换时反复整体后移
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)（原地扩容，不计字符串本身存储）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/string/kamacoder-0054-replace-digits.html
 *
 * 相关题目推荐：
 *   剑指 Offer 05. 替换空格
 *   344. 反转字符串
 *   151. 反转字符串中的单词
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    // 原地，所以需要原字符串扩容+解题小巧思：双指针是核心，逆向遍历是精髓
    string s;
    while (cin >> s) {
        // 统计数字个数，扩容在老数组基础上加上净增量，因此不用再统计字母数量了
        int num_count = 0;
        for (char ch: s) {
            if (ch >= '0' && ch <= '9') {
                num_count++;
            }
        }
        int old_index = s.size() - 1;
        // 数字换成 number（6 位）净增 5 位
        s.resize(s.size() + num_count * 5);
        int new_index = s.size() - 1;
        // 循环条件不用担心old_index越界，因为两个新旧索引其实在一定程度上是同步的，有内在联系
        // 比如可以理解成new在追赶old，最终在0处相遇，所以同时为0只需判断其一
        while (new_index >= 0) {
            // 从后向前填充，若从前向后填充则是 O(n^2)，每次插入都要把后面的元素整体后移
            if (s[old_index] >= '0' && s[old_index] <= '9') {
                s[new_index--] = 'r';
                s[new_index--] = 'e';
                s[new_index--] = 'b';
                s[new_index--] = 'm';
                s[new_index--] = 'u';
                s[new_index--] = 'n';
                old_index--;
            } else {
                s[new_index--] = s[old_index--];
            }
        }
        // 这里是cpp。直接cout s就可以了
        for (char ch: s) {
            cout << ch;
        }
    }
    // 打印不能写在这，不然只会打印第一个案例，巨大错误
    return 0;
}
