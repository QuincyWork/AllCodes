#include <gtest/gtest.h>
using namespace std;

/*
����һ������ǰ�������������������������
ע��:
����Լ�������û���ظ���Ԫ�ء�
���磬����
ǰ����� preorder = [3,9,20,15,7]
������� inorder = [9,3,15,20,7]
�������µĶ�������
	3
   / \
  9  20
	/  \
   15   7

   TreeNode SubTree(I,PRE,IN,L,R)
		R(PRE[I])
		M = FIND IN 
		R.L = SubTree(PRE,IN,L,M-1)
		R.R = GetSub(PRE,IN,M+1,R)
		

*/

namespace IV11_2
{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class Solution {
	public:
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			

		}

		TreeNode* buildSubTree(TreeNode* root, vector<int>& preorder, vector<int>& inorder, int left, int right)
		{

		}
	};
}