#include <gtest/gtest.h>
#include <vector>
using namespace std;

namespace LC654
{
	/*
	给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：

	二叉树的根是数组 nums 中的最大元素。
	左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
	右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
	返回有给定数组 nums 构建的 最大二叉树 。

	提示：

	1 <= nums.length <= 1000
	0 <= nums[i] <= 1000
	nums 中的所有整数 互不相同

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/maximum-binary-tree
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

	输入：nums = [3,2,1,6,0,5]
	输出：[6,3,5,null,2,0,null,null,1]
	*/


	/**
	* Definition for a binary tree node.*/
	 struct TreeNode {
	     int val;
	     TreeNode *left;
	     TreeNode *right;
	     TreeNode() : val(0), left(nullptr), right(nullptr) {}
	     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	 };
 
	class Solution {
	public:
		TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

			return constructSubMaximumBinaryTree(nums, 0, nums.size() - 1);
		}

		TreeNode* constructSubMaximumBinaryTree(vector<int>& nums, int left, int right) {

			if (left > right) {
				return nullptr;
			}

			// 查找最大值索引
			int max = left;
			int max_value = nums[left];
			for (int i = left+1; i <= right; ++i) {
				if (nums[i] > max_value) {
					max = i;
					max_value = nums[i];
				}
			}

			TreeNode* root = new TreeNode(max_value);
			
			// 计算左最大子树
			root->left = constructSubMaximumBinaryTree(nums,left,max-1);

			// 计算右最大子树
			root->right = constructSubMaximumBinaryTree(nums,max+1,right);

			return root;
		}
	};

	TEST(LeetCodeCN, constructMaximumBinaryTree)
	{
		Solution s;
		std::vector<int> data1 = { 3,2,1,6,0,5 };
		auto result = s.constructMaximumBinaryTree(data1);

		std::vector<int> data2 = { 3,2,1 };
		result = s.constructMaximumBinaryTree(data2);
	}
}