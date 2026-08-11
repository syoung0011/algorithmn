/**
 * LeetCode 704. 二分查找
 * https://leetcode.cn/problems/binary-search/
 *
 * 题目：给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target，
 *       写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
 *
 * 思路：经典二分查找，采用左闭右闭区间 [left, right]
 *       1. while (left <= right)，因为 left == right 时区间仍然有效
 *       2. middle = left + (right - left) / 2，防止 left + right 溢出
 *       3. 收缩边界时 middle 已经比较过，因此 left = middle + 1 / right = middle - 1
 *
 * 复杂度：时间复杂度 O(log n)，空间复杂度 O(1)
 *
 * 参考：代码随想录-数组篇-二分查找
 *
 * 相关题目推荐：
 *   35. 搜索插入位置
 *   34. 在排序数组中查找元素的第一个和最后一个位置
 *   69. x 的平方根
 *   367. 有效的完全平方数
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;  // 左闭右闭区间 [left, right]
        while (left <= right) {
            int middle = left + (right - left) / 2;  // 防止溢出
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    cout << solution.search(nums1, 9) << endl;  // 期望输出 4
    cout << solution.search(nums1, 2) << endl;  // 期望输出 -1

    vector<int> nums2 = {5};
    cout << solution.search(nums2, 5) << endl;  // 期望输出 0
    cout << solution.search(nums2, -5) << endl; // 期望输出 -1

    return 0;
}
