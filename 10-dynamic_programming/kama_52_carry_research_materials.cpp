/**
 * 卡码网 52. 携带研究材料（完全背包问题，ACM 模式）
 * https://kamacoder.com/problempage.php?pid=1052
 *
 * 题目：小明要参加国际科学大会，需携带若干研究材料，行李箱能承担的总重量为 v。
 *       每种材料有重量和价值，且每种材料可以选择无数次（可重复选择），求可携带
 *       的材料的最大总价值。
 *
 * 输入：第一行为两个整数 n、v，n 为材料种类数，v 为行李所能承担的总重量；
 *       接下来 n 行，每行两个整数 wi、vi，表示第 i 种材料的重量和价值。
 *
 * 输出：一个整数，表示最大价值（vi 可达 10^9，需用 long long 存储）。
 *
 * 思路：完全背包，容量为 v，dp[j] 表示容量 j 的背包能装的
 *      最大价值，dp[j] = max(dp[j], dp[j - weights[i]] + values[i])；与 01 背包
 *      唯一的区别是一维数组写法中背包容量需正序遍历，这样同一物品可以重复放入
 *
 * 复杂度：时间复杂度 O(nv)，空间复杂度 O(v)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/dynamic-programming/complete-knapsack-basics.html
 *
 * 相关题目推荐：
 *   卡码网 46. 携带研究材料（01 背包）
 *   LeetCode 518. 零钱兑换 II
 *   LeetCode 322. 零钱兑换
 *   LeetCode 279. 完全平方数
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, v;
    if (!(cin >> n >> v)) {
        return 0;
    }

    vector<int> weights(n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    vector<int> dp(v + 1);
    for (int j = 1; j <= v; j++) {
        for (int i = 0; i < n; i++) {
            // 这个实际是可以用二维，也可先遍历物品，那样还能省一个if，因为把判断融入循环判断
            // 但是为了便于记忆，不如直接顺序一维
            if (j >= weights[i]) {
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
    }
    cout << dp[v];
    return 0;
}
