/**
 * LeetCode 55. 跳跃游戏
 * https://leetcode.cn/problems/jump-game/
 *
 * 题目：给你一个非负整数数组 nums，你最初位于数组的第一个下标。数组中的每个
 *       元素代表你在该位置可以跳跃的最大长度。判断你是否能够到达最后一个下标。
 *
 * 思路：贪心，维护能到达的最远位置，遍历过程中不断更新，若覆盖到了终点即可达
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0055-jump-game.html
 *
 * 相关题目推荐：
 *   45. 跳跃游戏 II
 *   1306. 跳跃游戏 III
 *   1345. 跳跃游戏 IV
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        // 写法一，不推荐
        // int temp = 0;
        // // 逻辑比较复杂，虽然也是覆盖范围，但是没有官网逻辑清晰
        // for (int i = 0; i < nums.size(); i++) {
        //     // 为了单独处理特殊情况，改成了 >=，其实完全可以提出去
        //     if (nums[i] + i >= temp) {
        //         temp = nums[i] + i;
        //         if (temp >= nums.size() - 1) {
        //             return true;
        //         }
        //     }
        //     // 条件二应该是多余的
        //     if (i == temp && nums[i] == 0) {
        //         return false;
        //     }
        // }
        // // 空数组兜底，之所以不放在开头，因为力扣需要有兜底才能不报错
        // return false;

        // 官网写法，推荐，重点看循环
        if (nums.size() == 1) return true;
        int cover = 0;
        // 最核心的就是这个循环，不是从头遍历到尾，而是这个覆盖区间的动态循环，如同单向滑动窗口
        for (int i = 0; i <= cover; i++) {
            // 最好用max，要记住，不然不像会写算法的，而且也是为了减少一次显示加法运算num + i
            if (nums[i] + i > cover) {
                cover = nums[i] + i;
                if (cover >= nums.size() - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << (solution.canJump(nums1) ? "true" : "false") << endl; // 期望输出 true

    // 示例 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << (solution.canJump(nums2) ? "true" : "false") << endl; // 期望输出 false

    return 0;
}
