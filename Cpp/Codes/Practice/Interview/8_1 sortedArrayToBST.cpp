#include <gtest/gtest.h>
using namespace std;

/*
��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������
�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��
ʾ��:
������������: [-10,-3,0,5,9],

һ�����ܵĴ��ǣ�[0,-3,9,-10,null,5]�������Ա�ʾ��������߶�ƽ�������������

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

