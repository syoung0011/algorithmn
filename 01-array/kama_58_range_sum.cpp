/**
 * 卡码网 58. 区间和（ACM 模式）
 * https://kamacoder.com/
 *
 * 题目：给定一个整数数组，以及多个查询区间 [a, b]，输出每个区间内元素的和。
 *
 * 输入：第一行为整数 n，表示数组长度；第二行为 n 个整数；
 *       之后每行两个整数 a、b 表示查询区间（闭区间），直到文件结束。
 *
 * 思路：前缀和，p[i] 表示前 i 个元素之和，区间和 = p[b+1] - p[a]
 *
 * 复杂度：时间复杂度 预处理 O(n)，每次查询 O(1)，设查询次数为 q，则 O(n + q)，空间复杂度 O(n)
 *
 * 参考：代码随想录-数组篇-前缀和
 *
 * 相关题目推荐：
 *   303. 区域和检索 - 数组不可变
 *   560. 和为 K 的子数组
 *   238. 除自身以外数组的乘积
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);    // 其实可删去，参考题目需求。循环体内改为变量
    vector<int> pre(n); // 前缀和[0,idx]
    int sum = 0;    // 引入sum可以少写一些逻辑，或者省去一次循环，尽管复杂度不变
    for (int i = 0; i < n; i++) {   // 主要时间复杂度融入输入，不代表复杂度O(1)
        cin >> nums[i]; // 追求效率改用c的io
        sum += nums[i];
        pre[i] = sum;
    }
    int left,right;
    while (cin >> left >> right) { // io写在while里
        int res;
        if (left == 0) res = pre[right];    // 特殊情况分支处理
        else res = pre[right] - pre[left - 1]; // 非常巧妙，不用left再加上nums[left]，而是用left-1
        cout << res << endl;    // 可换\n提高效率
    }
    return 0;
}