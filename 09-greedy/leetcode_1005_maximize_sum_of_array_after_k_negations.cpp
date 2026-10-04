/**
 * LeetCode 1005. K 次取反后最大化的数组和
 * https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/
 *
 * 题目：给你一个整数数组 nums 和一个整数 k，按以下方法修改该数组：选择某个下标
 *       i 并将 nums[i] 替换为 -nums[i]。重复这个过程恰好 k 次。可以多次选择
 *       同一个下标 i。以这种方式修改数组后，返回数组可能的最大和。
 *
 * 思路：贪心，按绝对值从大到小排序，优先翻转负数；若 k 还有剩余且为奇数，翻转绝对值最小的数
 *
 * 复杂度：时间复杂度 O(nlogn)（排序复杂度占大头，别忘了），空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/1005-maximize-sum-of-array-after-k-negations.html
 *
 * 相关题目推荐：
 *   561. 数组拆分
 *   1046. 最后一块石头的重量
 *   881. 救生艇
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        int sum = 0;
        // 和官网不同，这里用了两次排序来确定取反目标
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 这种情况可以合二为一个if
            if (k > 0) {
                if (nums[i] < 0) {
                    nums[i] = -nums[i];
                    k--;
                }
            }
            // 此时sum已经加的是更新过的，无需再写一个循环，如果是算法比赛，可以不注意这些，结果才是重要的，过程复杂无所谓
            sum += nums[i];
        }
        if (k & 0x1) {
            // 不要写成while(k--)如果k很大呢，这里直接一个判断奇偶
            sort(nums.begin(), nums.end());
            sum -= (nums[0] << 1);
        }
        return sum;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {4, 2, 3};
    cout << solution.largestSumAfterKNegations(nums1, 1) << endl; // 期望输出 5

    // 示例 2
    vector<int> nums2 = {3, -1, 0, 2};
    cout << solution.largestSumAfterKNegations(nums2, 3) << endl; // 期望输出 6

    // 示例 3
    vector<int> nums3 = {2, -3, -1, 5, -4};
    cout << solution.largestSumAfterKNegations(nums3, 2) << endl; // 期望输出 13

    return 0;
}
