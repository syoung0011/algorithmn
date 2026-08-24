/**
 * LeetCode 15. 三数之和
 * https://leetcode.cn/problems/3sum/
 *
 * 题目：给你一个整数数组 nums，判断是否存在三元组 [nums[i], nums[j], nums[k]]
 *       满足 i != j、i != k 且 j != k，同时还满足 nums[i] + nums[j] + nums[k] == 0。
 *       返回所有和为 0 且不重复的三元组。
 *
 * 思路：排序 + 双指针，固定一个数后左右指针向中间收缩，注意去重
 *
 * 复杂度：时间复杂度 O(n^2)，空间复杂度 O(1)（不计输出数组，sort 为原地排序，栈开销 O(log n) 通常忽略）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/hash-table/0015-3sum.html
 *
 * 相关题目推荐：
 *   1. 两数之和
 *   18. 四数之和
 *   16. 最接近的三数之和
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        // 如果用哈希，一定要想到1+2还是2+1，虽然复杂度没变，但是实操一下就知道2+1要保存2个索引，而且还可能多个情况，就知道复杂了
        // 而且这题要想到数学上的轮换对称，i,j,k三个字母谁都可以是那个i，所以要去重，我想的是强制i<j<k
        // 因为限定大小顺序，循环就很好写，j=i+1，k=j+1就行了。
        // 假如没有顺序，自己写循环就要聪明点，你依旧j取所有索引，在循环体内判断j==i，而不是融入循环条件或者分两次i-1和i+1两侧循环
        // 后面仍然要去重，因为ijk谁都可以取重复值，都要去重，而且也同样要求排序，否则没办法去重，除非再引入集合去重，可能就太复杂了
        // 难点很多，导致我没做成功，直接跑路换下面方法了，难点仍然在于去重
        vector<vector<int> > res; // 无需初始化n=0，这个应该是默认的
        // 排序一是输出结果比对需要，二是去重必要，后续两次去重都依赖有序
        sort(nums.begin(), nums.end()); // algorithmn库
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)return res; // 提前
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重a方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                int sum = nums[i] + nums[left] + nums[right]; // 引用>1次就抽取，习惯
                if (sum < 0)left++;
                else if (sum > 0)right--;
                // 不能省else，不然不等于0等情形也会执行下面代码，细心点
                else {
                    // 这理解难度可以说必须得举例子吧
                    // 先push再去重太巧妙了，完美规避了-1 -1 2的left越界去重的情况
                    // 然后去重也是双向分别去重，用left<right限制，也是非常巧妙
                    // 又要考虑为何不是right+1和right比，这可能又要举例子，暂时不管，这里是先辈找后辈，不同于之前的后辈找先辈
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1])right--;
                    while (left < right && nums[left] == nums[left + 1])left++;
                    // 两者都要偏移也比较难理解，假如无重复不走while就秒懂了
                    // 当然就算去重，最后出循环仍然是重复的，数字都没变，所以要换数字
                    right--;
                    left++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    for (const auto &triple: solution.threeSum(nums1)) {
        cout << "[" << triple[0] << "," << triple[1] << "," << triple[2] << "] ";
    }
    cout << endl;
    // 期望输出 [-1,-1,2] [-1,0,1]（顺序不限）

    // 示例 2
    vector<int> nums2 = {0, 1, 1};
    for (const auto &triple: solution.threeSum(nums2)) {
        cout << "[" << triple[0] << "," << triple[1] << "," << triple[2] << "] ";
    }
    cout << endl;
    // 期望输出为空

    // 示例 3
    vector<int> nums3 = {0, 0, 0};
    for (const auto &triple: solution.threeSum(nums3)) {
        cout << "[" << triple[0] << "," << triple[1] << "," << triple[2] << "] ";
    }
    cout << endl;
    // 期望输出 [0,0,0]

    return 0;
}
