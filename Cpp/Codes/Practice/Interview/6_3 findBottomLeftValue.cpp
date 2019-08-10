#include <gtest/gtest.h>
#include <queue>
using namespace std;

/*
给定一个二叉树，在树的最后一行找到最左边的值。
示例 1:
输入:

	2
   / \
  1   3

输出:
1

示例 2:
输入:

		1
	   / \
	  2   3
	 /   / \
	4   5   6
	   /
	  7

输出:
7
*/


namespace IV6_3
{
	/** Definition for a binary tree node.*/
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}		
	};

	class Solution {
	public:

		// 相当于二叉树的广度遍历算法
		int findBottomLeftValue(TreeNode* root) {
			
			queue<TreeNode*> q{ {root} };
			while (!q.empty()) {
				root = q.front();
				q.pop();
				
				if (root->right) 
					q.push(root->right);

				if (root->left) 
					q.push(root->left);

			}

			return root->val;
		}
	};

	TEST(Interview, findBottomLeftValue)
	{
		Solution s;
		TreeNode d[] = { 1,2,3,4,5,6,7 };
		d[0].left = &d[1];
		d[0].right = &d[2];
		d[1].left = &d[3];
		d[2].left = &d[4];
		d[2].right = &d[5];
		d[4].left = &d[6];


		ASSERT_EQ(s.findBottomLeftValue(d), 7);
		
	}
}