#include <gtest/gtest.h>
using namespace std;

namespace LC106
{
	/*
	根据一棵树的中序遍历与后序遍历构造二叉树。

	注意:
	你可以假设树中没有重复的元素。

	例如，给出

	中序遍历 inorder = [9,3,15,20,7]
	后序遍历 postorder = [9,15,7,20,3]
	返回如下的二叉树：

		3
	   / \
	  9  20
		/  \
	   15   7

	*/
	//Definition for a binary tree node.
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
		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

			return buildSubTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
		}

		TreeNode* buildSubTree(vector<int>& inorder, int inleft, int inright, 
			vector<int>& postorder,int postleft, int postright) {

			if (postleft > postright) {
				return nullptr;
			}
			// 根节点
			auto rootValue = postorder[postright];
			auto root = new TreeNode(rootValue);
			int index = inleft;
			for (int i = inleft; i <= inright; ++i) {
				if (inorder[i] == rootValue) {
					index = i;
					break;
				}
			}

			int postindex = postleft + index - inleft;
			// 左子树
			root->left = buildSubTree(inorder, inleft, index - 1, postorder, postleft, postindex-1);
			// 右子树
			root->right = buildSubTree(inorder, index + 1, inright, postorder, postindex, postright - 1);

			return root;
		}
	};

	TEST(LeetCodeCN, buildTree)
	{
		Solution s;
		vector<int> preData{ 9,3,15,20,7 };
		vector<int> inData{ 9,15,7,20,3 };
		auto result = s.buildTree(preData, inData);
	}
}