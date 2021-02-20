#include <gtest/gtest.h>
#include <Common/Tree.h>
using namespace std;

namespace LC236
{
	/*
	给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
	百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

	输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
	输出：3
	解释：节点 5 和节点 1 的最近公共祖先是节点 3 。

	提示：

		树中节点数目在范围 [2, 105] 内。
		-109 <= Node.val <= 109
		所有 Node.val 互不相同 。
		p != q
		p 和 q 均存在于给定的二叉树中。
	*/

	class Solution {
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

			if (!root) {
				return nullptr;
			}

			if (root->val == p->val ||
				root->val == q->val) {
				return root;
			}

			auto left = lowestCommonAncestor(root->left, p, q);
			auto right = lowestCommonAncestor(root->right, p, q);

			if (left && right) {
				return root;
			}

			return left ? left : right;
		}
	};

	TEST(LeetCodeCN, lowestCommonAncestor)
	{
		Solution s;
		auto d1 = Tree::toTree("3,5,1,6,2,0,8,null,null,7,4");
		auto r1 = s.lowestCommonAncestor(*d1.get(), &TreeNode(5), &TreeNode(1));
		ASSERT_EQ(r1->val, 3);

		auto d2 = Tree::toTree("1,2");
		auto r2 = s.lowestCommonAncestor(*d2.get(), &TreeNode(1), &TreeNode(2));
		ASSERT_EQ(r2->val, 1);
	}
}