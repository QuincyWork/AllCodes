#include <gtest/gtest.h>
#include <queue>
using namespace std;

/*
����һ�����������ҳ�����С��ȡ�
��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
ʾ��:
���������� [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
����������С���  2.
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
			
			/// ���ö������Ĺ�ȱ����㷨
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