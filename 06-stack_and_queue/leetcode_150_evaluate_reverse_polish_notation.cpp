/**
 * LeetCode 150. 逆波兰表达式求值
 * https://leetcode.cn/problems/evaluate-reverse-polish-notation/
 *
 * 题目：给你一个字符串数组 tokens，表示一个根据逆波兰表示法表示的算术表达式，
 *       请你计算该表达式，返回一个表示表达式值的整数。
 *
 * 思路：栈模拟，数字入栈，遇运算符弹出两个数字计算后入栈
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/stack-queue/0150-evaluate-reverse-polish-notation.html
 *
 * 相关题目推荐：
 *   224. 基本计算器
 *   227. 基本计算器 II
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOperation(const string &s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    int cal(int left,int right,string s) {
        if (s == "+") {
            return left + right;
        }
        if (s == "-") {
            return left - right;
        }
        if (s == "*") {
            return left * right;
        }
        if (s == "/") {
            // 应注意除数为0，只是力扣条件不包括
            return left / right;
        }
        return 0; // 力扣编译器，不写这句会报错
    }
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        // 不存原始字符串，而是存数字，这里如果怕溢出，应该用LL
        stack<int> st;
        for (string s : tokens) {
            if (isOperation(s)) {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(cal(left,right,s));
            } else {
                st.push(stoi(s));
            }
        }
        // 不要直接return。因为栈里面还有东西，应该注意及时释放栈上内存
        int ret= st.top();
        st.pop();
        return ret;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << solution.evalRPN(tokens1) << endl;  // 期望输出 9

    // 示例 2
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << solution.evalRPN(tokens2) << endl;  // 期望输出 6

    // 示例 3
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << solution.evalRPN(tokens3) << endl;  // 期望输出 22

    return 0;
}
