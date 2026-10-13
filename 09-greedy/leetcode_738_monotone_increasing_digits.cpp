/**
 * LeetCode 738. 单调递增的数字
 * https://leetcode.cn/problems/monotone-increasing-digits/
 *
 * 题目：当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是
 *       单调递增的。给定一个整数 n，返回小于或等于 n 的最大数字，且数字呈
 *       单调递增。
 *
 * 思路：贪心，从后往前找第一个递减位置，该位减 1 并记录位置，其后全部置 9
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0738-monotone-increasing-digits.html
 *
 * 相关题目推荐：
 *   402. 移掉 K 位数字
 *   316. 去除重复字母
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        int flag = num.size();
        for (int i = num.size() - 1; i > 0; i--) {
            if (num[i - 1] > num[i]) {
                num[i - 1]--;
                flag = i;
            }
        }
        for (int i = flag; i < num.size(); i++) {
            num[i] = '9';
        }
        return stoi(num);
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << solution.monotoneIncreasingDigits(10) << endl; // 期望输出 9

    // 示例 2
    cout << solution.monotoneIncreasingDigits(1234) << endl; // 期望输出 1234

    // 示例 3
    cout << solution.monotoneIncreasingDigits(332) << endl; // 期望输出 299

    return 0;
}
