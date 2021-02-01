#include <gtest/gtest.h>
#include <stack>
using namespace std;

namespace LC105
{
	/*
	根据一棵树的前序遍历与中序遍历构造二叉树。

	注意:
	你可以假设树中没有重复的元素。

	例如，给出

	前序遍历 preorder = [3,9,20,15,7]
	中序遍历 inorder = [9,3,15,20,7]
	返回如下的二叉树：

		3
	   / \
	  9  20
		/  \
	   15   7
	*/

	/**
	 Definition for a binary tree node.*/
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
		
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

			return buildSubTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
		}

		TreeNode* buildSubTree(vector<int>& preorder, int preleft, int preright,
			vector<int>& inorder, int inleft, int inright) {

			if (preleft > preright) {
				return nullptr;
			}

			// 根节点处理
			int rootValue = preorder[preleft];
			int index = inleft;
			for (int i = inleft; i <= inright; ++i) {
				if (inorder[i] == rootValue) {
					index = i;
					break;
				}
			}

			int presubright = preleft + index - inleft;
			auto root = new TreeNode(rootValue);

			// 左子节点
			root->left = buildSubTree(preorder, preleft+1,presubright,inorder,inleft, index-1);
			// 右子节点
			root->right = buildSubTree(preorder,presubright+1,preright,inorder,index+1,inright);

			return root;
		}

		TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {

			if (preorder.empty()) {
				return nullptr;
			}

			int rootValue = preorder[0];
			auto root = new TreeNode(rootValue);
			std::stack<TreeNode*> stack;
			stack.push(root);
			int inorderIndex = 0;

			for (int i = 1; i < preorder.size(); ++i) {
				int preValue = preorder[i];
				auto top = stack.top();
				if (top->val != inorder[inorderIndex]) {
					top->left = new TreeNode(preValue);
					stack.push(top->left);
				}
				else {

					while (!stack.empty() && stack.top()->val == inorder[inorderIndex]) {

						top = stack.top();
						stack.pop();
						++inorderIndex;
					}

					top->right = new TreeNode(preValue);
					stack.push(top->right);
				}
			}

			return root;
		}
	};

	TEST(LeetCodeCN, buildTree)
	{
		Solution s;
		vector<int> preData{ 3,9,20,15,7 };
		vector<int> inData{ 9,3,15,20,7 };
		auto result = s.buildTree1(preData, inData);

	}
}