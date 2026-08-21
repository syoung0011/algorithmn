/**
 * LeetCode 383. 赎金信
 * https://leetcode.cn/problems/ransom-note/
 *
 * 题目：给你两个字符串 ransomNote 和 magazine，判断 ransomNote 能不能由
 *       magazine 里面的字符构成。magazine 中的每个字符只能在 ransomNote
 *       中使用一次。如果可以，返回 true；否则返回 false。
 *
 * 思路：数组哈希统计 magazine 字符频次，再扣减 ransomNote
 *
 * 复杂度：时间复杂度 O(m + n)，其中m表示ransomNote的长度，n表示magazine的长度，空间复杂度 O(1)
 * 从逻辑上，确实m，n是正常顺序，但是我不知道为啥总想着n，m，还是从众吧
 *
 * 参考：代码随想录 https://programmercarl.com/algo/hash-table/0383-ransom-note.html
 *
 * 相关题目推荐：
 *   242. 有效的字母异位词
 *   49. 字母异位词分组
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        // 特殊情况，短的必须重复才会组成更长，这就不合题意了
        // 不写也可以，只是效率上欠佳，因为就算一个if判断重复n遍，开销仍然忽略不计，和里面循环做n*m遍不是一个量级
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        // 也可用索引遍历，那个可能更清晰些
        for (char ch: magazine) {
            hash[ch - 'a']++;
        }
        for (char ch: ransomNote) {
            // 提取了索引出来，因为两处调用
            // 但其实这只是一个习惯而已，不要因为多了一步而粗心犯错
            int index = ch - 'a';
            // 答案颠倒顺序，先减然后判断改成<0，但这样就有点不清晰了，因为这里<0其实就是==-1，那不如写清楚等等
            if (hash[index] == 0)return false;
            hash[index]--;
        }
        return true;
    }
};

int main() {
    Solution solution;

    // 示例 1
    cout << (solution.canConstruct("a", "b") ? "true" : "false") << endl; // 期望输出 false

    // 示例 2
    cout << (solution.canConstruct("aa", "ab") ? "true" : "false") << endl; // 期望输出 false

    // 示例 3
    cout << (solution.canConstruct("aa", "aab") ? "true" : "false") << endl; // 期望输出 true

    return 0;
}
