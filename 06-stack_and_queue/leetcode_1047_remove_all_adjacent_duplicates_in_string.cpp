/**
 * LeetCode 1047. 删除字符串中的所有相邻重复项
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
 *
 * 题目：给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的字母，
 *       并删除它们。在 s 上反复执行重复项删除操作，直到无法继续删除。
 *       返回完成所有重复项删除操作后返回最终的字符串。
 *
 * 思路：栈模拟，当前字符与栈顶相同则出栈，否则入栈
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/stack-queue/1047-remove-all-adjacent-duplicates-in-string.html
 *
 * 相关题目推荐：
 *   1209. 删除字符串中的所有相邻重复项 II
 *   1544. 整理字符串
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        // 可以直接用字符串作为栈，用push_back和pop_back就行，然后就无需栈转字符串以及倒置了
        stack<char> st;
        for (char ch: s) {
            if (!st.empty() && ch == st.top()) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        string ret;
        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end()); // 而不是ret=reverse
        return ret;
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.removeDuplicates("abbaca") << endl; // 期望输出 ca

    // 示例 2
    cout << solution.removeDuplicates("azxxzy") << endl; // 期望输出 ay

    return 0;
}
