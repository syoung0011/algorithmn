/**
 * LeetCode 108. 将有序数组转换为二叉搜索树
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
 *
 * 题目：给你一个整数数组 nums，其中元素已经按升序排列，请你将其转换为一棵
 *       高度平衡二叉搜索树。高度平衡二叉树是一棵满足「每个节点的左右两个子树
 *       的高度差的绝对值不超过 1」的二叉树。
 *
 * 思路：递归，取中间元素作为根，左右区间递归构建
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n * log n)（每层都要新建左右两个数组）
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0108-convert-sorted-array-to-binary-search-tree.html
 *
 * 相关题目推荐：
 *   TODO 迭代法
 *   654. 最大二叉树
 *   1382. 将二叉搜索树变平衡
 */

#include <iostream>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        // vector没有非法构造，只是[0,0)时nums空
        // 本题可以不用构造，类似left, right二分查找，复杂度可变成log n
        if (nums.empty()) return nullptr;

        // int mid = nums.size() - 1 >> 1; // 偏左
        int mid = nums.size() >> 1; // 偏右，与测试案例对应

        TreeNode *node = new TreeNode(nums[mid]);
        vector<int> left = vector<int>(nums.begin(), nums.begin() + mid);
        vector<int> right = vector<int>(nums.begin() + mid + 1, nums.end());
        node->left = sortedArrayToBST(left);
        node->right = sortedArrayToBST(right);
        return node;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    TreeNode *root1 = solution.sortedArrayToBST(nums1);
    printTree(root1); // 期望输出 [0,-3,9,-10,null,5]
    deleteTree(root1); // 构造出的新树需手动释放

    // 示例 2
    vector<int> nums2 = {1, 3};
    TreeNode *root2 = solution.sortedArrayToBST(nums2);
    printTree(root2); // 期望输出 [3,1]
    deleteTree(root2);

    return 0;
}
