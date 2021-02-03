#pragma once
#include <gtest/gtest.h>
#include <stack>
using namespace std;

namespace LC538
{
	/*
	给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

	提醒一下，二叉搜索树满足下列约束条件：

	节点的左子树仅包含键 小于 节点键的节点。
	节点的右子树仅包含键 大于 节点键的节点。
	左右子树也必须是二叉搜索树。
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
		TreeNode* convertBST(TreeNode* root) {

			// 根据二叉树特性，大于节点的所以节点在右子树上，可以采用旋转的中序遍历算法，
			// 从右子树开始的中序遍历

			int sum = 0;
			auto current = root;
			stack<TreeNode*> stack;
			while (true) {

				while (current) {
					stack.push(current);
					current = current->right;
				}
				
				if (stack.empty()) {
					break;
				}

				current = stack.top();
				stack.pop();
				current->val += sum;
				sum = current->val;

				current = current->left;
			}

			return root;
		}

		int convertSubBST(TreeNode* root) {
			if (!root) {
				return 0;
			}

			return root->val;
		}
	};

	TEST(LeetCodeCN, convertBST)
	{
		Solution s;
		TreeNode data[] = { 3,1,4,2 };
		data[0].left = &data[1];
		data[0].right = &data[2];
		data[1].right = &data[3];

		auto result = s.convertBST(data);
	}
}
