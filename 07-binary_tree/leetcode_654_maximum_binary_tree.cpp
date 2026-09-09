/**
 * LeetCode 654. 最大二叉树
 * https://leetcode.cn/problems/maximum-binary-tree/
 *
 * 题目：给定一个不重复的整数数组 nums，构建一棵最大二叉树：
 *       根是数组中最大的元素，左子树是最大值左边部分的最大二叉树，
 *       右子树是最大值右边部分的最大二叉树。返回该最大二叉树。
 *
 * 思路：递归，找到区间最大值作为根，左右递归构建
 *
 * 复杂度：时间复杂度 O(n * h)，空间复杂度 O(n * h)
 *
 * 参考：代码随想录 https://programmercarl.com/algo/binary-tree/0654-maximum-binary-tree.html
 *
 * 相关题目推荐：
 *   105. 从前序与中序遍历序列构造二叉树
 *   106. 从中序与后序遍历序列构造二叉树
 */

#include <iostream>
#include <vector>
#include "tree_node.h"
#include <climits>

using namespace std;

class Solution {
public:
    int findMaxIndex(vector<int> &vec) {
        int curMax = INT_MIN;
        int index = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] > curMax) {
                curMax = vec[i];
                index = i;
            }
        }
        return index;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        int index = findMaxIndex(nums);
        TreeNode *node = new TreeNode(nums[index]);

        // 必须自己构造对象，直接传临时对象，由于参数指定非const引用，右值无法作为参数
        vector<int> leftNums = vector<int>(nums.begin(), nums.begin() + index);
        node->left = constructMaximumBinaryTree(leftNums);
        // 也可不用冗余的拷贝初始化，对比上者
        // 最好判断下index范围，但好像不会越界这里
        vector<int> rightNums(nums.begin() + index + 1, nums.end());
        node->right = constructMaximumBinaryTree(rightNums);
        return node;
    }
};

int main() {
    Solution solution;

    // 示例 1
    vector<int> nums1 = {3, 2, 1, 6, 0, 5};
    TreeNode *root1 = solution.constructMaximumBinaryTree(nums1);
    printTree(root1); // 期望输出 [6,3,5,null,2,0,null,null,1]
    deleteTree(root1); // 构造出的新树需手动释放

    // 示例 2
    vector<int> nums2 = {3, 2, 1};
    TreeNode *root2 = solution.constructMaximumBinaryTree(nums2);
    printTree(root2); // 期望输出 [3,null,2,null,1]
    deleteTree(root2);

    return 0;
}
