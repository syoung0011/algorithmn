/**
 * LeetCode 20. 有效的括号
 * https://leetcode.cn/problems/valid-parentheses/
 *
 * 题目：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s，判断字符串
 *       是否有效。有效字符串需满足：左括号必须用相同类型的右括号闭合；
 *       左括号必须以正确的顺序闭合；每个右括号都有一个对应的相同类型的左括号。
 *
 * 思路：栈匹配，左括号入栈，右括号与栈顶比较
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/stack-queue/0020-valid-parentheses.html
 *
 * 相关题目推荐：
 *   22. 括号生成
 *   32. 最长有效括号
 *   301. 删除无效的括号
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isRight(char ch) {
        return ch == ')' || ch == '}' || ch == ']';
    }

    bool isMatch(char left, char right) {
        switch (left) {
            case '(':
                return right == ')';
            case '{':
                return right == '}';
            case '[':
                return right == ']';
            default:
                return false;
        }
    }

    bool isValid(string s) {
        stack<char> st;
        for (char ch: s) {
            if (isRight(ch)) {
                if (!st.empty() && isMatch(st.top(), ch)) {
                    st.pop();
                } else {
                    // 尽管只有一条依据，但是还是用{}，这样更规范清晰。如果是单if则可省
                    return false;
                }
            } else {
                // 也可直接push对应的右括号，用多个if来判断，这样就不用isMatch函数，逻辑简化很多
                st.push(ch);
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << (solution.isValid("()") ? "true" : "false") << endl; // 期望输出 true

    // 示例 2
    cout << (solution.isValid("()[]{}") ? "true" : "false") << endl; // 期望输出 true

    // 示例 3
    cout << (solution.isValid("(]") ? "true" : "false") << endl; // 期望输出 false

    // 示例 4
    cout << (solution.isValid("([)]") ? "true" : "false") << endl; // 期望输出 false

    return 0;
}
