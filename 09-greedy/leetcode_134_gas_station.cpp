/**
 * LeetCode 134. 加油站
 * https://leetcode.cn/problems/gas-station/
 *
 * 题目：在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。你有一辆
 *       油箱容量无限的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油
 *       cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。给定两个整数数组
 *       gas 和 cost，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，
 *       否则返回 -1。如果存在解，则保证它是唯一的。
 *
 * 思路：贪心，总油量不足则无解；否则从累计剩余油量最小的位置之后出发
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0134-gas-station.html
 *
 * 相关题目推荐：
 *   53. 最大子数组和
 *   135. 分发糖果
 *   1400. 构造 K 个回文字符串
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int curSum = 0;
        int totalSum = 0;
        // 不要初始化为-1这种非法值，不然会错过0这个情况，因为循环本质还是单向遍历，不是循环，所以idx0无法判断
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            // 经典多个数组那就差值，不过股票那个是一个数组，但是前后关系出现差值
            curSum += (gas[i] - cost[i]);
            totalSum += (gas[i] - cost[i]);
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if (totalSum < 0) {
            return -1;
        }
        return start;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << solution.canCompleteCircuit(gas1, cost1) << endl; // 期望输出 3

    // 示例 2
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << solution.canCompleteCircuit(gas2, cost2) << endl; // 期望输出 -1

    return 0;
}
