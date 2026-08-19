/**
 * LeetCode 349. 两个数组的交集
 * https://leetcode.cn/problems/intersection-of-two-arrays/
 *
 * 题目：给定两个数组 nums1 和 nums2，返回它们的交集。输出结果中的每个元素
 *       一定是唯一的。可以不考虑输出结果的顺序。
 *
 * 思路：unordered_set 去重，遍历 nums2 判断是否在集合中
 *
 * 复杂度：时间复杂度 O(m + n)（m、n 分别为 nums1、nums2 长度，set 转 vector 的开销被遍历 nums2 吸收，等价于 O(max(m,n))）
 * 空间复杂度 O(n)（上界）/ O(k)（上确界）（n 为 nums1 长度，k 为 nums1 去重后大小，最坏情况 set 存满去重元素，不计输出数组）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/hash-table/0349-intersection-of-two-arrays.html
 *
 * 相关题目推荐：
 *   350. 两个数组的交集 II
 *   217. 存在重复元素
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 若未限定范围，用数组哈希就会浪费大量空间，只能集合，本题由于限定了数值大小，也可以用数组。
        // 判断元素是否存在集合中，优先想到哈希
        unordered_set<int> nums_set(nums1.begin(), nums1.end()); // 直接装nums1，省去一个循环插入
        unordered_set<int> res_set;
        for (int num : nums2) {
            if (nums_set.find(num)!=nums_set.end()) {
                // 自动去重
                res_set.insert(num);
            }
        }
        return vector<int>(res_set.begin(),res_set.end());
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    for (int num : solution.intersection(nums1, nums2)) {
        cout << num << " ";  // 期望输出 2
    }
    cout << endl;

    // 示例 2
    vector<int> nums3 = {4, 9, 5};
    vector<int> nums4 = {9, 4, 9, 8, 4};
    for (int num : solution.intersection(nums3, nums4)) {
        cout << num << " ";  // 期望输出 9 4（顺序不限）
    }
    cout << endl;

    return 0;
}
