#include <gtest/gtest.h>
#include <math.h>
using namespace std;

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

#if 0

int countNodes(TreeNode* root) 
{
	if (root==NULL)
	{
		return 0;
	}

	return countNodes(root->left) + countNodes(root->right) + 1;
}

#endif

#if 0
int getMaxHeight(TreeNode* root)
{
	int height = 0;
	while (root)
	{
		height++;
		root = root->left;
	}

	return height;
}

bool countLackNodes(TreeNode* root, int current, int height, int& result)
{
	if (current == height)
	{
		if (root)
		{
			return false;
		}

		result++;
		return true;
	}
	else
	{
		return countLackNodes(root->right,current+1,height,result) &&
			   countLackNodes(root->left,current+1,height,result);
	}
}

int countNodes(TreeNode* root) 
{
	if (!root)
	{
		return 0;
	}

	int height = getMaxHeight(root);
	int lackNodes = 0;
	countLackNodes(root,1,height,lackNodes);

	int result = 0;
	for (int i=0; i<height; ++i)
	{
		result += (1 << i);
	}
	
	return result-lackNodes;
}
#endif

// 找到最后一层的最后一个节点，可以判断左右节点最最左边的层数是否相同，如果相同，则左子树为满二叉树，若不同则右子树为满二叉树

int GetHeight(TreeNode* root)
{
	int height = 0;
	while (root)
	{
		height++;
		root = root->left;
	}

	return height;
}

int countNodes(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	int left = GetHeight(root->left);
	int right = GetHeight(root->right);
	
	if (left == right)
	{
		return (1 << left) + countNodes(root->right);
	}
	else
	{
		return (1 << right) + countNodes(root->left);	
	}
}


TEST(LeetCodeMock,tCountNodes)
{
	TreeNode d1[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	d1[0].left = &d1[1];
	d1[0].right = &d1[2];
	d1[1].left = &d1[3];
	d1[1].right = &d1[4];
	d1[2].left = &d1[5];
	d1[2].right = &d1[6];
	d1[3].left = &d1[7];
	d1[3].right = &d1[8];
	d1[4].left = &d1[9];
	d1[4].right = &d1[10];
	d1[5].left = &d1[11];	

	ASSERT_EQ(countNodes(&d1[0]),12);
}