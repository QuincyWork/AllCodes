#include <gtest/gtest.h>
#include <queue>
using namespace std;

/*
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明: 叶子节点是指没有子节点的节点。
示例:
给定二叉树 [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
返回它的最小深度  2.
*/

namespace IV13_1
{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}		
	};

	class Solution {
	public:
		int minDepth(TreeNode* root) {
			
			/// 采用二叉树的广度遍历算法
			if (!root)
			{
				return 0;
			}

			int depth = 0;
			queue<pair<TreeNode*,int>> cache;
			cache.push(make_pair(root,1));
			while (!cache.empty())
			{
				
				auto v = cache.front();
				cache.pop();
				if (v.first->left == NULL && v.first->right == NULL)
				{
					depth = v.second;
					break;
				}

				if (v.first->left != NULL)
				{
					cache.push(make_pair(v.first->left, v.second + 1));
				}

				if (v.first->right != NULL)
				{
					cache.push(make_pair(v.first->right, v.second + 1));
				}
			}

			return depth;
		}
	};

	TEST(Interview, minDepth)
	{
		Solution s;
		TreeNode d[] = { 3,9,20,15,7 };
		d[0].left = &d[1];
		d[0].right = &d[2];
		d[2].left = &d[3];
		d[2].right = &d[4];

		ASSERT_EQ(s.minDepth(d), 2);
	}
}