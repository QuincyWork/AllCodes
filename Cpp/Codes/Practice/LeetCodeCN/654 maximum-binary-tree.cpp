#include <gtest/gtest.h>
#include <vector>
using namespace std;

namespace LC654
{
	/*
	����һ�������ظ�Ԫ�ص��������� nums ��һ���Դ�����ֱ�ӵݹ鹹���� �������� �������£�

	�������ĸ������� nums �е����Ԫ�ء�
	��������ͨ�������� ���ֵ��߲��� �ݹ鹹���������������
	��������ͨ�������� ���ֵ�ұ߲��� �ݹ鹹���������������
	�����и������� nums ������ �������� ��

	��ʾ��

	1 <= nums.length <= 1000
	0 <= nums[i] <= 1000
	nums �е��������� ������ͬ

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/maximum-binary-tree
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

	���룺nums = [3,2,1,6,0,5]
	�����[6,3,5,null,2,0,null,null,1]
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

			// �������ֵ����
			int max = left;
			int max_value = nums[left];
			for (int i = left+1; i <= right; ++i) {
				if (nums[i] > max_value) {
					max = i;
					max_value = nums[i];
				}
			}

			TreeNode* root = new TreeNode(max_value);
			
			// �������������
			root->left = constructSubMaximumBinaryTree(nums,left,max-1);

			// �������������
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