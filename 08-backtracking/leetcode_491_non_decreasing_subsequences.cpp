/**
 * LeetCode 491. 递增子序列
 * https://leetcode.cn/problems/non-decreasing-subsequences/
 *
 * 题目：给你一个整数数组 nums，找出并返回所有该数组中不同的递增子序列，递增
 *       子序列中至少有两个元素。你可以按任意顺序返回答案。数组中可能含有重复
 *       元素，解集不能包含重复的子序列。
 *
 * 思路：回溯法，同层用 set 去重，且保证路径非递减；注意不能排序，排序会破坏原数组相对顺序
 *
 * 复杂度：时间复杂度 O(n · 2^n)（每个元素选/不选构成至多 2^n 个节点，每个节点还要遍历
 *        本层剩余元素做 set 的 find/insert 计 O(n)，收集时拷贝 path 也计 O(n)，相乘得 n 倍）
 *        空间复杂度 O(n)（path + 递归栈深度；不计输出结果）
 *        注：若把「递归栈上逐层存活的 unordered_set」也计入，严格为 O(n^2)；
 *        官网标注即 O(n * 2^n) / O(n)，与本分析一致，
 *        官网省略了「n 因子来自本层 set 遍历 + path 拷贝」的说明，也未提及层级 set 的 O(n^2) 口径
 *
 * 参考：代码随想录 https://programmercarl.com/algo/backtracking/0491-non-decreasing-subsequences.html
 *
 * 相关题目推荐：
 *   78. 子集
 *   90. 子集 II
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<int> > res;
vector<int> path;

class Solution {
public:
    // 不用used去重，因为相同元素不一定相邻，以前的判断逻辑失效了，那就搬上去重的经典方法：集合
    void dfs(const vector<int> &nums, int index) {
        if (path.size() > 1) {
            res.push_back(path);
        }
        unordered_set<int> uset;
        for (int i = index; i < nums.size(); i++) {
            // path.size() > 0 可用 empty, path[path.size()-1 可用 path.back()
            // &&要理解，不可重复是大条件，虽然setfind包括了path空，但由于&&所以需要再单独写
            // 官网的continue形式会更好
            if ((path.size() == 0)
            || (path.size() > 0 && nums[i] >= path[path.size()-1])
            && uset.find(nums[i]) == uset.end()) {
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();
        dfs(nums, 0);
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {4, 6, 7, 7};
    for (const auto& sub : solution.findSubsequences(nums1)) {
        cout << "[";
        for (size_t i = 0; i < sub.size(); ++i) {
            cout << sub[i] << (i + 1 < sub.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [4,6] [4,6,7] [4,6,7,7] [4,7] [4,7,7] [6,7] [6,7,7] [7,7]

    // 示例 2
    vector<int> nums2 = {4, 4, 3, 2, 1};
    for (const auto& sub : solution.findSubsequences(nums2)) {
        cout << "[";
        for (size_t i = 0; i < sub.size(); ++i) {
            cout << sub[i] << (i + 1 < sub.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << endl;
    // 期望输出 [4,4]

    return 0;
}
