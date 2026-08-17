/**
 * LeetCode 209. 长度最小的子数组
 * https://leetcode.cn/problems/minimum-size-subarray-sum/
 *
 * 题目：给定一个含有 n 个正整数的数组和一个正整数 target，找出该数组中满足其
 *       总和大于等于 target 的长度最小的连续子数组，并返回其长度。
 *       如果不存在符合条件的子数组，返回 0。
 *
 * 思路：滑动窗口，右指针扩展窗口，左指针收缩窗口
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录-数组篇-长度最小的子数组
 *
 * 相关题目推荐：
 *   TODO 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log n) 时间复杂度的解法。（方法二：前缀和 + 二分查找）
 *   76. 最小覆盖子串
 *   3. 无重复字符的最长子串
 *   438. 找到字符串中所有字母异位词
 *   904. 水果成篮
 */

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int i = 0;
        int sum = 0;
        // 也可nums.size()+1，之所以+1是因为本身也算子序列
        int min_length = INT32_MAX;
        // 此处也可不初始化，但一般无脑初始化0，一种习惯吧。不过有时也可仅声明
        int temp_length = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                temp_length = j - i + 1;
                min_length = min_length < temp_length ? min_length : temp_length;
                sum -= nums[i++];
            }
        }
        return min_length == INT32_MAX ? 0 : min_length;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    cout << solution.minSubArrayLen(7, nums1) << endl; // 期望输出 2

    // 示例 2
    vector<int> nums2 = {1, 4, 4};
    cout << solution.minSubArrayLen(4, nums2) << endl; // 期望输出 1

    // 示例 3
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << solution.minSubArrayLen(11, nums3) << endl; // 期望输出 0

    return 0;
}
