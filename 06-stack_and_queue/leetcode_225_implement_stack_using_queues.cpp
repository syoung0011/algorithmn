/**
 * LeetCode 225. 用队列实现栈
 * https://leetcode.cn/problems/implement-stack-using-queues/
 *
 * 题目：请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部
 *       四种操作：push、top、pop 和 empty。
 *       每次调用 pop 和 top 都保证栈不为空
 *
 * 思路：单队列法，入栈时将新元素插入队尾后把前面元素
 *       依次移到队尾，或使用两个队列互相倒换
 *
 * 复杂度：略
 *
 * 参考：代码随想录 https://programmercarl.com/algo/stack-queue/0225-implement-stack-using-queues.html
 *
 * 相关题目推荐：
 *   232. 用栈实现队列
 *   155. 最小栈
 */

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {
        // 默认
    }

    void push(int x) {
        _queue.push(x);
    }

    // 题目条件下无需考虑边界溢出
    int pop() {
        // 怕多引入变量，比如int loop=size-1，可以直接融入到for循环内局部变量i
        // 或者len=size -> len-- -> while(len--)，中间不引入变量，用自减调整循环次数
        for (int i = _queue.size() - 1; i > 0; i--) {
            _queue.push(_queue.front());
            _queue.pop();
        }
        int ret = _queue.front();
        _queue.pop();
        return ret;
    }

    int top() {
        int ret = pop(); // 不是queue.pop
        push(ret); // 也可以queue.push，单队列两者是等价的
        return ret;
    }

    bool empty() {
        return _queue.empty();
    }

private:
    // 一个队列就可以了，逻辑非常简便
    queue<int> _queue;
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << endl; // 期望输出 2
    cout << myStack.pop() << endl; // 期望输出 2
    cout << myStack.empty() << endl; // 期望输出 0（false）

    return 0;
}
