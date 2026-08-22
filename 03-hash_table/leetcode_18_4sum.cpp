/**
 * LeetCode 18. 四数之和
 * https://leetcode.cn/problems/4sum/
 *
 * 题目：给你一个由 n 个整数组成的数组 nums 和一个目标值 target，请你找出并
 *       返回满足 nums[a] + nums[b] + nums[c] + nums[d] == target 且不重复的
 *       四元组 [nums[a], nums[b], nums[c], nums[d]]。
 *
 * 思路：排序 + 两层循环固定前两个数 + 双指针收缩，双层去重
 *
 * 复杂度：时间复杂度 O(n^3)，空间复杂度 O(1)（不计输出数组）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/hash-table/0018-4sum.html
 *
 * 相关题目推荐：
 *   1. 两数之和
 *   15. 三数之和
 *   454. 四数相加 II
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end()); // 别忘了要先排序！
        // 也可以多个size<4的剪枝，这里省了。而且划不来，为了极为稀缺的特殊情况而增加了n次判断的开销
        for (int a = 0; a < nums.size(); a++) {
            // 剪枝，条件2：nums[a]>=0应该是最完美的压缩，这里target>=0会漏掉一些情况
            if (nums[a] > target && target >= 0)break;
            if (a > 0 && nums[a] == nums[a - 1])continue; // 去重
            for (int b = a + 1; b < nums.size(); b++) {
                // 这里要处理溢出，非常隐蔽
                if ((long long) nums[a] + nums[b] > target && target >= 0)break; // 同上
                if (b > a + 1 && nums[b] == nums[b - 1])continue;
                int left = b + 1, right = nums.size() - 1;
                while (left < right) {
                    // 注意题目范围，会溢出（爆int）
                    // long(4B)可能和int(2/4B)同范围，所以ll更保险
                    long long sum = 0LL + nums[a] + nums[b] + nums[left] + nums[right]; // 也可强转
                    if (sum > target)right--;
                    else if (sum < target)left++;
                    else {
                        // 依旧先保存再去重，避免漏掉情况
                        res.push_back({nums[a], nums[b], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])left++;
                        while (left < right && nums[right] == nums[right - 1])right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    for (const auto &quad: solution.fourSum(nums1, 0)) {
        cout << "[" << quad[0] << "," << quad[1] << "," << quad[2] << "," << quad[3] << "] ";
    }
    cout << endl;
    // 期望输出 [-2,-1,1,2] [-2,0,0,2] [-1,0,0,1]（顺序不限）

    // 示例 2
    vector<int> nums2 = {2, 2, 2, 2, 2};
    for (const auto &quad: solution.fourSum(nums2, 8)) {
        cout << "[" << quad[0] << "," << quad[1] << "," << quad[2] << "," << quad[3] << "] ";
    }
    cout << endl;
    // 期望输出 [2,2,2,2]

    return 0;
}
