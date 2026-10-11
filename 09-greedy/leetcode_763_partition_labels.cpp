/**
 * LeetCode 763. 划分字母区间
 * https://leetcode.cn/problems/partition-labels/
 *
 * 题目：给你一个字符串 s。我们要把这个字符串划分为尽可能多的片段，同一字母最多
 *       出现在一个片段中。返回一个表示每个字符串片段的长度的列表。
 *
 * 思路：贪心，先记录每个字符最后出现的位置，遍历时更新当前片段右边界，到达边界即划分
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(1)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/greedy/0763-partition-labels.html
 *
 * 相关题目推荐：
 *   56. 合并区间
 *   435. 无重叠区间
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 而不是给每个字符的都加上一个int标记
        int hash[26] = {0};
        vector<int> res;
        for (int i = 0; i < s.length(); i++) {
            hash[s[i] - 'a'] = max(i, hash[s[i] - 'a']);
        }
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            right = max(right, hash[s[i] - 'a']);
            if (right == i) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    for (int len: solution.partitionLabels("ababcbacadefegdehijhklij")) {
        cout << len << " "; // 期望输出 9 7 8
    }
    cout << endl;

    // 示例 2
    for (int len: solution.partitionLabels("eccbbbbdec")) {
        cout << len << " "; // 期望输出 10
    }
    cout << endl;

    return 0;
}
