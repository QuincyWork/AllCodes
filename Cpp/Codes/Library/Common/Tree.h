#pragma once
#include <string>

// Tree�ṹ�Ķ���ͳ�ʼ��

//Definition for a tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree
{
public:

	template<typename T>
	TreeNode* operator() (const std::string& input) const
	{

	}

	
};