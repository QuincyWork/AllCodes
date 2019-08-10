#include <gtest/gtest.h>
using namespace std;

/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

	  0
	 / \
   -3   9
   /   /
 -10  5
*/

namespace IV8_1
{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class Solution {
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums) {

			return sortedArrayToBSTEx(nums,0, nums.size() - 1);
		}

		TreeNode* sortedArrayToBSTEx(vector<int>& nums, int left, int right)
		{
			if (left > right)
			{
				return nullptr;
			}

			int mid = left + (right - left) / 2;
			auto node = new TreeNode(nums[mid]);
			auto leftnode = sortedArrayToBSTEx(nums, left, mid - 1);
			if (leftnode != nullptr)
			{
				node->left = leftnode;
			}
			
			auto rightnode = sortedArrayToBSTEx(nums, mid + 1, right);
			if (rightnode != nullptr)
			{
				node->right = rightnode;
			}

			return node;
		}
	};

	TEST(Interview, sortedArrayToBST)
	{
		Solution s;
		auto root = s.sortedArrayToBST(vector<int> {-10, -3, 0, 5, 9});
	}
}

