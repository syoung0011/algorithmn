/**
 * LeetCode 860. 柠檬水找零
 * https://leetcode.cn/problems/lemonade-change/
 *
 * 题目：在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，一次
 *       购买一杯。每个顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。
 *       你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
 *       注意，一开始你手头没有任何零钱。如果你能给每位顾客正确找零，返回 true，
 *       否则返回 false。
 *
 * 思路：贪心，记录 5/10 美元数量，收 20 时优先用 10+5 找零，其次用 3 张 5 找零
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0860-lemonade-change.html
 *
 * 相关题目推荐：
 *   455. 分发饼干
 *   406. 根据身高重建队列
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0;
        int ten = 0;
        // 没必要统计20，用不着
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            } else if (bills[i] == 20) {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << (solution.lemonadeChange(bills1) ? "true" : "false") << endl; // 期望输出 true

    // 示例 2
    vector<int> bills2 = {5, 5, 10, 10, 20};
    cout << (solution.lemonadeChange(bills2) ? "true" : "false") << endl; // 期望输出 false

    return 0;
}
