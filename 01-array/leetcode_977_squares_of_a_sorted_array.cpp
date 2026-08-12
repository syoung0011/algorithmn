/**
 * LeetCode 977. 有序数组的平方
 * https://leetcode.cn/problems/squares-of-a-sorted-array/
 *
 * 题目：给你一个按非递减顺序排序的整数数组 nums，返回每个数字的平方组成的新数组，
 *       要求也按非递减顺序排序。
 *
 * 思路：双指针法。平方后的最大值一定在原数组两端，用 i、j 分别指向首尾，
 *       比较两端平方值，大的从新数组末尾开始倒序装填，直至两指针相遇。
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)
 *
 * 参考：代码随想录-数组篇-有序数组的平方
 *
 * 相关题目推荐：
 *   167. 两数之和 II - 输入有序数组
 *   88. 合并两个有序数组
 *   344. 反转字符串
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());  // 必须预先分配大小，否则 result[idx] 越界写入
        int idx=nums.size()-1;
        for (int i=0,j=idx;i<=j;) {
            if (nums[i]*nums[i]>nums[j]*nums[j]) {
                result[idx--]=nums[i]*nums[i];  // 别误写成idx-1
                i++;
            }
            else {
                result[idx--]=nums[j]*nums[j];
                j--;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    for (int num : solution.sortedSquares(nums1)) {
        cout << num << " ";  // 期望输出 0 1 9 16 100
    }
    cout << endl;

    // 示例 2
    vector<int> nums2 = {-7, -3, 2, 3, 11};
    for (int num : solution.sortedSquares(nums2)) {
        cout << num << " ";  // 期望输出 4 9 9 49 121
    }
    cout << endl;

    return 0;
}
