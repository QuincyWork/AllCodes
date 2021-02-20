#include <gtest/gtest.h>
#include <Common/Tree.h>
using namespace std;

namespace LC700
{
	/*
	����������������BST���ĸ��ڵ��һ��ֵ�� ����Ҫ��BST���ҵ��ڵ�ֵ���ڸ���ֵ�Ľڵ㡣 �����Ըýڵ�Ϊ���������� ����ڵ㲻���ڣ��򷵻� NULL��

	���磬

	��������������:

			4
		   / \
		  2   7
		 / \
		1   3

	��ֵ: 2
	��Ӧ�÷�����������:

		  2     
		 / \   
		1   3
	������ʾ���У����Ҫ�ҵ�ֵ�� 5������Ϊû�нڵ�ֵΪ 5������Ӧ�÷��� NULL��

	*/

	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
	 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	 * };
	 */
	class Solution {
	public:
		TreeNode* searchBST(TreeNode* root, int val) {

			if (!root) {
				return nullptr;
			}

			if (root->val == val) {
				return root;
			}
			else if (root->val > val) {
				return searchBST(root->left, val);
			}
			else {
				return searchBST(root->right, val);
			}
		}

		TreeNode* searchBST1(TreeNode* root, int val) {

			while (root && root->val != val) {
				if (root->val > val) {
					root = root->left;
				}
				else {
					root = root->right;
				}
			}

			return root;
		}
	};

	TEST(LeetCodeCN, searchBST)
	{
		Solution s;
		auto data = Tree::toTree("4,2,7,1,3");
		auto result = s.searchBST1(*data.get(), 2);
		ASSERT_EQ(Tree::toString(result), "2,1,3");
	}
}