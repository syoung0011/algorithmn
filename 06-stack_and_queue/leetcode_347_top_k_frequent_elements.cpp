/**
 * LeetCode 347. 前 K 个高频元素
 * https://leetcode.cn/problems/top-k-frequent-elements/
 *
 * 题目：给你一个整数数组 nums 和一个整数 k，请你返回其中出现频率前 k 高的元素。
 *       你可以按任意顺序返回答案。
 *
 * 思路：哈希表统计频率 + 小顶堆维护前 k 个高频元素
 *
 * 复杂度：时间复杂度 O(nlog k)，空间复杂度 O(n)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/stack-queue/0347-top-k-frequent-elements.html
 *
 * 相关题目推荐：
 *   215. 数组中的第 K 个最大元素
 *   692. 前 K 个高频单词
 *   451. 根据字符出现频率排序
 */

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
// 显示包含pair，原本是靠vector等stl间接包含
#include <utility>

using namespace std;

class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        for (int num: nums) {
            // 不必用insert之类的
            umap[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (auto entry : umap) {
            // for : 自动解引用迭代器，所以不用push(*it)，所以这里用entry命名，比it合适
            // 但是for(begin;end)就是迭代器需要解引用
            pri_que.push(entry);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        // 指定长度，就可以倒置赋值（构造升序结果集），不然只能正序插入
        vector<int> res(k);
        for (int i=k-1;i>=0;i--) {
            // 从堆顶pop，别想着从尾部倒序遍历了
            res[i]=pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    for (int num: solution.topKFrequent(nums1, 2)) {
        cout << num << " "; // 期望输出 1 2（顺序不限）
    }
    cout << endl;

    // 示例 2
    vector<int> nums2 = {1};
    for (int num: solution.topKFrequent(nums2, 1)) {
        cout << num << " "; // 期望输出 1
    }
    cout << endl;

    return 0;
}
