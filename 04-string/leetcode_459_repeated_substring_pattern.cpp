/**
 * LeetCode 459. 重复的子字符串
 * https://leetcode.cn/problems/repeated-substring-pattern/
 *
 * 题目：给定一个非空的字符串 s，检查是否可以通过由它的一个子串重复多次构成。
 *
 * 思路：KMP，若存在重复子串，len % (len - next[len-1]) == 0；
 *       或移动匹配法：s+s 去掉首尾后查找 s
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/string/0459-repeated-substring-pattern.html
 *
 * 相关题目推荐：
 *   // TODO 移动匹配方法
 *   28. 找出字符串中第一个匹配项的下标
 *   686. 重复叠加字符串匹配
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // s虽不修改也&，然后用个const修饰，这是为了节省拷贝
    void getNext(vector<int> &next,const string &s) {
        int j = 0;
        next[0] = 0;
        // 也可以next.size
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if (len == 0) {
            return false;
        }
        vector<int> next(len, 0);
        getNext(next, s);
        // next[len-1]代表最长相等前后缀长度，具体逻辑见官网或视频
        if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0) return true;
        return false;
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << (solution.repeatedSubstringPattern("abab") ? "true" : "false") << endl; // 期望输出 true

    // 示例 2
    cout << (solution.repeatedSubstringPattern("aba") ? "true" : "false") << endl; // 期望输出 false

    // 示例 3
    cout << (solution.repeatedSubstringPattern("abcabcabcabc") ? "true" : "false") << endl; // 期望输出 true

    return 0;
}
