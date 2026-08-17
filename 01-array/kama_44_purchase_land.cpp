/**
 * 卡码网 44. 开发商购买土地（ACM 模式）
 * https://kamacoder.com/
 *
 * 题目：将一个 n 行 m 列的矩阵横向或纵向切成两部分，使得两部分元素之和的
 *       差的绝对值最小，输出这个最小差值。
 *
 * 输入：第一行为两个整数 n、m，表示矩阵行列数；接下来 n 行每行 m 个整数。
 *
 * 思路：二维前缀和，枚举每一行/每一列作为切割线
 *
 * 复杂度：时间复杂度 O(n×m)（读入 + 两次前缀统计 + 枚举切割 O(n+m)），空间复杂度 O(m+n) / O(1)（仅统计额外变量，不计输入矩阵）
 *
 * 参考：代码随想录-数组篇-开发商购买土地
 *
 * 相关题目推荐：
 *   304. 二维区域和检索 - 矩阵不可变
 *   303. 区域和检索 - 数组不可变
 *   238. 除自身以外数组的乘积
 */

#include <cstdint>
#include <iostream>
#include <vector>
// 显示包含，min，去掉也可以，但是依赖传递包含不可靠
#include <algorithm>
#include <cstdlib>  // 显示包含，abs

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > nums(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
        }
    }
    // 按行划分前缀和，也可以省去数组，每一行结束统计一次情况，具体见网站代码
    vector<int> pre_row(n, 0);
    int sum_row = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 其实这里理解上，很容易写出sum_row这个冗余变量，看下面列循环，完全可用pre动态记录
            sum_row += nums[i][j];
        }
        pre_row[i] = sum_row;
    }
    vector<int> pre_col(m, 0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            pre_col[j] += nums[i][j];
        }
    }
    // 数据规模大建议long long & LLONG_MAX（<climits>），abs和min可能也要提升
    int res = INT32_MAX;
    for (int i = 0; i < n - 1; i++) {
        // 这里有别于网站代码，没有left-1，而是按缝隙划分，且左右边界不符合实际不考虑
        int res_row = pre_row[n - 1] - 2 * pre_row[i];
        // 可用min函数，见如下列循环
        res = res < abs(res_row) ? res : abs(res_row);
    }
    for (int j = 0; j < m - 1; j++) {
        int res_col = pre_col[m - 1] - 2 * pre_col[j];
        res = min(res, abs(res_col));
    }
    cout << res << endl;
    return 0;
}
