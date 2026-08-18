/**
 * LeetCode 242. 有效的字母异位词
 * https://leetcode.cn/problems/valid-anagram/
 *
 * 题目：给定两个字符串 s 和 t，编写一个函数来判断 t 是否是 s 的字母异位词。
 *       字母异位词指字母相同但排列不同的字符串。
 *
 * 思路：数组哈希，统计 26 个字母出现次数，比较两个计数数组
 *
 * 复杂度：时间复杂度 O(?)，空间复杂度 O(?)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/hash-table/0242-valid-anagram.html
 *
 * 相关题目推荐：
 *   49. 字母异位词分组
 *   438. 找到字符串中所有字母异位词
 *   383. 赎金信
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 将字符串看成字符数组，先分别排序，再遍历比较对应位置也非常好，总之多角度思考。
        int hash[26] = {0}; // 全置0
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }
        // 无需再新建个数组存储t，那样两个数组比较异同就很繁
        // 直接让s的数组对应--，判断是否全为0
        for (int i = 0; i < t.size(); i++) {
            hash[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0)return false;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << (solution.isAnagram("anagram", "nagaram") ? "true" : "false") << endl; // 期望输出 true

    // 示例 2
    cout << (solution.isAnagram("rat", "car") ? "true" : "false") << endl; // 期望输出 false

    return 0;
}
