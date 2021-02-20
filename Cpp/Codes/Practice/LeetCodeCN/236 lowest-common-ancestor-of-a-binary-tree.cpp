#include <gtest/gtest.h>
#include <Common/Tree.h>
using namespace std;

namespace LC236
{
	/*
	����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
	�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q������������ȱ�ʾΪһ���ڵ� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

	���룺root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
	�����3
	���ͣ��ڵ� 5 �ͽڵ� 1 ��������������ǽڵ� 3 ��

	��ʾ��

		���нڵ���Ŀ�ڷ�Χ [2, 105] �ڡ�
		-109 <= Node.val <= 109
		���� Node.val ������ͬ ��
		p != q
		p �� q �������ڸ����Ķ������С�
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