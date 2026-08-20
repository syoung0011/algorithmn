/**
 * LeetCode 1. 两数之和
 * https://leetcode.cn/problems/two-sum/
 *
 * 题目：给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出
 *       和为目标值 target 的那两个整数，并返回它们的数组下标。
 *       假设每种输入只会对应一个答案，不能使用两次相同的元素。
 *
 * 思路：unordered_map 记录 值->下标，遍历时查找 target - nums[i]
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)（不计输出数组）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/hash-table/0001-two-sum.html
 *
 * 相关题目推荐：
 *   15. 三数之和
 *   18. 四数之和
 *   167. 两数之和 II - 输入有序数组
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // 自己写的，思考为何kv这么设置，本题核心在于查找数值，所以k为值则会查找更快，v为索引，需要map而非set
        // unordered_map<int,int> nums_map;
        // for (int i=0;i<nums.size();i++) {
        //     if (nums_map.find(target-nums[i])!=nums_map.end()) {
        //         vector<int> res(0);
        //         res.push_back(nums_map[target-nums[i]]);
        //         res.push_back((i));
        //         return res;
        //     }
        //     nums_map.insert(pair<int,int>(nums[i],i)); // 显示构造pair
        // }
        // return {};

        // 不创建数组，直接返回{}，类似语法糖，需要单独抽出迭代器对象配合，简化算法
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = nums_map.find(target - nums[i]); // auto更方便
            if (iter != nums_map.end()) {
                return {iter->second, i}; // 保持索引升序
            }
            nums_map.emplace(nums[i], i); // 避免一次多余的临时对象pair的显示构造
        }
        return {};
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {2, 7, 11, 15};
    for (int num: solution.twoSum(nums1, 9)) {
        cout << num << " "; // 期望输出 0 1
    }
    cout << endl;

    // 示例 2
    vector<int> nums2 = {3, 2, 4};
    for (int num: solution.twoSum(nums2, 6)) {
        cout << num << " "; // 期望输出 1 2
    }
    cout << endl;

    // 示例 3
    vector<int> nums3 = {3, 3};
    for (int num: solution.twoSum(nums3, 6)) {
        cout << num << " "; // 期望输出 0 1
    }
    cout << endl;

    return 0;
}
