#include <gtest/gtest.h>
#include <Common/Tree.h>
using namespace std;

namespace LC700
{
	/*
	给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

	例如，

	给定二叉搜索树:

			4
		   / \
		  2   7
		 / \
		1   3

	和值: 2
	你应该返回如下子树:

		  2     
		 / \   
		1   3
	在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。

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