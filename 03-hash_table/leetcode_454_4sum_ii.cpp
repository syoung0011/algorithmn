/**
 * LeetCode 454. 四数相加 II
 * https://leetcode.cn/problems/4sum-ii/
 *
 * 题目：给你四个整数数组 nums1、nums2、nums3 和 nums4，数组长度都是 n，
 *       请你计算有多少个元组 (i, j, k, l) 能满足：
 *       nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0。
 *
 * 思路：分组哈希，先统计 nums1+nums2 的两数之和出现次数，再遍历 nums3+nums4 查找相反数
 *
 * 复杂度：时间复杂度 O(n^2)，空间复杂度 O(n^2)（最坏情况下A和B的值各不相同，相加产生的数字个数为 n^2）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/hash-table/0454-4sum-ii.html
 *
 * 相关题目推荐：
 *   1. 两数之和
 *   15. 三数之和
 *   18. 四数之和
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2,
                     vector<int> &nums3, vector<int> &nums4) {
        // 本题考点不是思路上的复杂，而是常人不敢这么想，总以为会有最简单的算法，实则靠的就是如何剥离4层循环
        // 从 O(n^4) -> O(n^2) 空间换时间，两层循环做两次，其实没有想象中的神秘，只是不敢尝试
        unordered_map<int, int> nums_12_map;
        int count = 0;
        // 也可用ABCD代替numx这种复杂的命名
        for (int num1: nums1) {
            for (int num2: nums2) {
                nums_12_map[num1 + num2]++; // 若map初始不为0则出错
            }
        }
        for (int num3: nums3) {
            for (int num4: nums4) {
                // 用 0-(num3,num4)更清晰
                int target = -num3 - num4;
                // find+[]取值一共两次哈希查找，建议抽离出iter
                if (nums_12_map.find(target) != nums_12_map.end()) {
                    // 为何是直接+，而不是乘之类的，这个需要理解，可以自己举例子
                    // 如果新增一个nums34_map，可能就是乘了
                    // 因为是遍历3,4每种情况的过程中，所以相当于+k*1也就是+k了
                    count += nums_12_map[target];
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl; // 期望输出 2

    // 示例 2
    vector<int> nums5 = {0};
    vector<int> nums6 = {0};
    vector<int> nums7 = {0};
    vector<int> nums8 = {0};
    cout << solution.fourSumCount(nums5, nums6, nums7, nums8) << endl; // 期望输出 1

    return 0;
}
