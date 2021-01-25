#include <gtest/gtest.h>

namespace LC116
{
	/*
	给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

	struct Node {
	  int val;
	  Node *left;
	  Node *right;
	  Node *next;
	}
	填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
	初始状态下，所有 next 指针都被设置为 NULL。

	进阶：
	你只能使用常量级额外空间。
	使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

	*/
	// Definition for a Node.
	class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node* next;

		Node() : val(0), left(NULL), right(NULL), next(NULL) {}
		Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
		Node(int _val, Node* _left, Node* _right, Node* _next)
			: val(_val), left(_left), right(_right), next(_next) {}
	};

	class Solution {
	public:
		Node* connect(Node* root) {
			if (!root) {
				return nullptr;
			}

			connectSub(root->left, root->right);
			return root;
		}

		void connectSub(Node* left, Node* right) {
			if (!left || !right) {
				return;
			}

			left->next = right;
			connectSub(left->left, left->right);
			connectSub(right->left, right->right);
			connectSub(left->right, right->left);
		}
	};

	TEST(LeetCodeCN, tConnect)
	{
		Solution s;
		Node data[] = { 1, 2, 3, 4, 5, 6, 7 };

		data[0].left = &data[1];
		data[0].right = &data[2];
		data[1].left = &data[3];
		data[1].right = &data[4];
		data[2].left = &data[5];
		data[2].right = &data[6];

		s.connect(data);
	}
}