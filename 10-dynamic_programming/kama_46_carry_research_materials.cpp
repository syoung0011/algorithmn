/**
 * 卡码网 46. 携带研究材料（01 背包问题，ACM 模式）
 * https://kamacoder.com/problempage.php?pid=1046
 *
 * 题目：小明要参加国际科学大会，需携带若干研究材料，行李空间为 N。每种材料有
 *       占用的空间和价值，每种材料只能选择一次（选或不选），不能切割。求可携带
 *       的材料的最大总价值。
 *
 * 输入：第一行为两个正整数 M、N，M 为材料种类数，N 为行李空间；
 *       第二行为 M 个正整数，表示每种材料所占空间；
 *       第三行为 M 个正整数，表示每种材料的价值。
 *
 * 思路：01 背包，容量为 N，dp[j] 表示容量 j 的背包能装的
 *      最大价值，dp[j] = max(dp[j], dp[j - costs[i]] + values[i])；一维数组写法
 *      需先遍历物品、再倒序遍历背包容量，保证每个物品只用一次
 *
 * 复杂度：时间复杂度 O(MN)，空间复杂度 O(N)
 *
 * 参考：代码随想录 https://programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-1.html
 *
 * 相关题目推荐：
 *   LeetCode 416. 分割等和子集
 *   LeetCode 1049. 最后一块石头的重量 II
 *   LeetCode 494. 目标和
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    // 不是while(cin)功能，每个测试用例单独运行一次，非法输入提前终止
    if (!(cin >> m >> n)) {
        return 0;
    }

    // 指定大小，方便依下标赋值
    vector<int> costs(m);
    vector<int> values(m);
    for (int i = 0; i < m; ++i) {
        cin >> costs[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> values[i];
    }

    // 二维dp
    // // n + 1,因为背包容量0是自带的
    // vector<vector<int>> dp(m, vector<int>(n + 1));
    // // 第一列可不初始化，因为都是0
    // for(int i = 0; i < m; i++){
    //     dp[i][0] = 0;
    // }
    // // 第一行初始化可以倒序，直到装不下终止，同理静默0。其实最巧妙的是直接从cost[i]开始顺序
    // for(int j = 0; j <= n; j++){
    //     if(j < costs[0]){
    //         dp[0][j] = 0;
    //     } else {
    //         dp[0][j] = values[0];
    //     }
    // }
    // // j <= n要注意，j - cost判断溢出
    // // 二维dp的for顺序和单层遍历顺序都无所谓，默认最简单的顺序即可
    // for(int i = 1; i < m; i++){
    //     for(int j = 1; j <= n; j++){
    //         // >= 0是必须的，不然就会错，因为虽然回退背包容量为0，但逻辑上是要放这个物品
    //         if(j - costs[i] >= 0){
    //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - costs[i]] + values[i]);
    //         } else {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    // }
    // // 打印dp，注意在最后打印
    // // for(int i = 0; i < m; i++){
    // //     for(int j = 0; j <= n; j++){
    // //         cout << dp[i][j] << ' ';
    // //     }
    // //     cout << endl;
    // // }
    // cout << dp[m-1][n];

    // 一维滚动dp
    vector<int> dp(n + 1);
    // 其实可以不用初始化第一行了，因为不依赖于上一行，而是上一趟dp数组，融入物品从0遍历
    for (int j = n; j > 0; j--) {
        if (j >= costs[0]) {
            dp[j] = values[0];
        } else break;
    }
    for (int i = 1; i < m; i++) {
        for (int j = n; j > 0; j--) {
            // if冗余了，直接融入 j 的循环表达式，与二维不同，不满足直接退循环，因为dp[j] = dp[j]也没意义
            if (j - costs[i] >= 0) {
                dp[j] = max(dp[j], dp[j - costs[i]] + values[i]);
            }
        }
    }
    cout << dp[n];
    return 0;
}
