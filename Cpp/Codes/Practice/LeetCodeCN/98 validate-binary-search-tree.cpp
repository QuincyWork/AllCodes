#include <gtest/gtest.h>
#include <Common/Tree.h>
#include <stack>
using namespace std;

namespace LC98
{
	/*
	给定一个二叉树，判断其是否是一个有效的二叉搜索树。

	假设一个二叉搜索树具有如下特征：

	节点的左子树只包含小于当前节点的数。
	节点的右子树只包含大于当前节点的数。
	所有左子树和右子树自身必须也是二叉搜索树。
	示例 1:

	输入:
		2
	   / \
	  1   3
	输出: true
	示例 2:

	输入:
		5
	   / \
	  1   4
 		 / \
 		3   6
	输出: false
	解释: 输入为: [5,1,4,null,null,3,6]。
 		 根节点的值为 5 ，但是其右子节点值为 4 。
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
		bool isValidBST(TreeNode* root) {

			return isValidBST(root, nullptr, nullptr);
		}

		bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {

			if (!root) {
				return true;
			}

			if (min && root->val <= min->val) {
				return false;
			}

			if (max && root->val >= max->val) {
				return false;
			}

			return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
		}

		// 中序遍历
		bool isValidBST1(TreeNode* root) {

			long long prevalue = (long long)numeric_limits<int>::min() - 1;
			stack<TreeNode*> stack;
			while (true){

				while (root) {
					stack.push(root);
					root = root->left;
				}

				if (stack.empty()) {
					break;
				}

				root = stack.top();
				stack.pop();

				if (root->val <= prevalue) {
					return false;
				}
				prevalue = root->val;
				root = root->right;
			}

			return true;
		}
	};

	TEST(LeetCodeCN, isValidBST)
	{
		Solution s;
		auto data = Tree::toTree("5,1,4,null,null,3,6");
		ASSERT_FALSE(s.isValidBST(*data.get()));
		ASSERT_FALSE(s.isValidBST1(*data.get()));

		data = Tree::toTree("5,4,6,null,null,3,7");
		ASSERT_FALSE(s.isValidBST(*data.get()));
		ASSERT_FALSE(s.isValidBST1(*data.get()));
	}
}