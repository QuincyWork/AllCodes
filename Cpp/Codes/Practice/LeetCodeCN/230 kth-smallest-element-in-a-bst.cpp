#include <gtest/gtest.h>
#include <stack>
using namespace std;

namespace LC230
{
	/*
	给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

	说明：
	你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

	示例 1:

	输入: root = [3,1,4,null,2], k = 1
	   3
	  / \
	 1   4
	  \
 	   2
	输出: 1
	示例 2:

	输入: root = [5,3,6,2,4,null,null,1], k = 3
		   5
		  / \
		 3   6
		/ \
	   2   4
	  /
	 1
	输出: 3
	进阶：
	如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
	*/

	// Definition for a binary tree node.
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
		int kthSmallest(TreeNode* root, int k) {
			
			int result = 0;
			kthSubSmallest(root, k, result);
			return result;
		}

		int kthSmallest1(TreeNode* root, int k) {

			if (!root) {
				return 0;
			}

			// 中序遍历
			int result = 0;
			stack<TreeNode*> stack;
			while (true) {

				while (root) {
					stack.push(root);
					root = root->left;
				}

				if (stack.empty()) {
					break;
				}

				root = stack.top();
				stack.pop();
				if (--k == 0) {
					result = root->val;
					break;
				}

				root = root->right;
			}

			return result;
		}

		void kthSubSmallest(TreeNode* root, int& k, int& result) {

			if (!root) {
				return;
			}

			kthSubSmallest(root->left, k, result);
			if (k == 0) {
				return;
			}

			if (--k == 0) {
				result = root->val;
				return;
			}

			kthSubSmallest(root->right, k, result);
		}
	};

	TEST(LeetCodeCN, kthSmallest)
	{
		Solution s;
		TreeNode data[] = { 3,1,4,2 };
		data[0].left = &data[1];
		data[0].right = &data[2];
		data[1].right = &data[3];
		ASSERT_EQ(s.kthSmallest(data, 1),1);
		ASSERT_EQ(s.kthSmallest(data, 3), 3);

		ASSERT_EQ(s.kthSmallest1(data, 1), 1);
		ASSERT_EQ(s.kthSmallest1(data, 3), 3);
	}
}