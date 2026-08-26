/**
 * LeetCode 232. 用栈实现队列
 * https://leetcode.cn/problems/implement-queue-using-stacks/
 *
 * 题目：请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作：
 *       push、pop、peek、empty。
 *       假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
 *
 * 思路：两个栈，进队列入 in 栈，出队列时若 out 为空则
 *       将 in 全部倒入 out
 *
 * 复杂度：略
 *
 * 参考：代码随想录 https://programmercarl.com/algo/stack-queue/0232-implement-queue-using-stacks.html
 *
 * 相关题目推荐：
 *   225. 用队列实现栈
 *   155. 最小栈
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
        // 默认即可，析构同理
    }

    void push(int x) {
        _stack1.push(x);
    }

    int pop() {
        int ret = 0;
        // 注意到支路1,3有共同语句可提取，且支路2在题目条件下可忽略，所以ret也可省去，参考peek代码
        if (!_stack2.empty()) {
            // pop无返回值，但top有，所以先top，再pop删除
            ret = _stack2.top();
        } else if (_stack1.empty()) {
            return ret;
        } else {
            while (!_stack1.empty()) {
                _stack2.push(_stack1.top());
                _stack1.pop();
            }
            ret = _stack2.top();
        }
        _stack2.pop();
        return ret;
    }

    int peek() {
        // 这里是复用pop代码，也可直接调用pop（复杂度不变），然后再push到stack2（而不是stack1）
        if (_stack2.empty()) {
            while (!_stack1.empty()) {
                _stack2.push(_stack1.top());
                _stack1.pop();
            }
        }
        return _stack2.top();
    }

    bool empty() {
        return _stack1.empty() && _stack2.empty();
    }

private:
    stack<int> _stack1, _stack2;
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    cout << myQueue.peek() << endl; // 期望输出 1
    cout << myQueue.pop() << endl; // 期望输出 1
    cout << myQueue.empty() << endl; // 期望输出 0（false）

    return 0;
}
