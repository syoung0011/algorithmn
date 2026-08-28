/**
 * LeetCode 239. 滑动窗口最大值
 * https://leetcode.cn/problems/sliding-window-maximum/
 *
 * 题目：给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到
 *       数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向
 *       右移动一位。返回滑动窗口中的最大值。
 *
 * 思路：单调队列（递减），队首始终是当前窗口最大值
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(k)（k为区间长度，虽然是常数，但不能写 O(1)）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/stack-queue/0239-sliding-window-maximum.html
 *
 * 相关题目推荐：
 *   76. 最小覆盖子串
 *   3. 无重复字符的最长子串
 *   155. 最小栈
 */

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 嵌套类，因为只有内部需要，所以用private更合理，不过显然不会有神人外部访问，语法上public也行
private:
    // 类不能自己充当容器，而是类的属性充当容器，类用于封装api
    // 所以就很像queue，底层却是deque。这也是queue默认的
    class MyQueue {
    public:
        deque<int> que; // 必须用双端队列，因为要pop_back

        void pop(int value) {
            if (!que.empty() && que.front() == value) {
                que.pop_front();
            }
        }

        void push(int value) {
            while (!que.empty() && que.back() < value) {
                que.pop_back();
            }
            que.push_back(value);
        }

        int front() {
            // 符合题目约束，无需验证empty
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyQueue que;
        vector<int> res;

        // 第一轮用下面循环会越界，所以自己额外处理
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        res.push_back(que.front()); // 保存结果
        // 模拟区间移动，非常巧妙
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]); // 左边出去的，但可能已经出去了
            que.push(nums[i]); // 右边新增的
            res.push_back(que.front()); // 保存结果
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 3, -1, -3, 5, 3, 6, 7};
    for (int num: solution.maxSlidingWindow(nums1, 3)) {
        cout << num << " "; // 期望输出 3 3 5 5 6 7
    }
    cout << endl;

    // 示例 2
    vector<int> nums2 = {1};
    for (int num: solution.maxSlidingWindow(nums2, 1)) {
        cout << num << " "; // 期望输出 1
    }
    cout << endl;

    return 0;
}
