/**
 * LeetCode 27. 移除元素
 * https://leetcode.cn/problems/remove-element/
 *
 * 题目：给你一个数组 nums 和一个值 val，需要原地移除所有数值等于 val 的元素，
 *       并返回移除后数组的新长度。不要使用额外的数组空间，仅使用 O(1) 额外空间。
 *
 * 思路：快慢双指针。快指针 fast 遍历原数组，遇到不等于 val 的元素就复制给
 *       慢指针 slow 指向的位置并让 slow 前移；slow 之前的区间即为移除后的新数组。
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录-数组篇-移除元素
 *
 * 相关题目推荐：
 *   26. 删除有序数组中的重复项
 *   283. 移动零
 *   844. 比较含退格的字符串
 *   977. 有序数组的平方
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            // 等于 val 的元素直接跳过，不复制
        }
        // 不是slow+1，因为循环退出已经+1了
        return slow;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {3, 2, 2, 3};
    cout << solution.removeElement(nums1, 3) << endl; // 期望输出 2

    // 示例 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << solution.removeElement(nums2, 2) << endl; // 期望输出 5

    return 0;
}
