#pragma once
#include <vector>

namespace TreeData
{
	//Definition for a tree node.
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	};

	std::vector<TreeNode> Data(std::initializer_list<int> list) {

		std::vector<TreeNode> result;
		for (auto& i : list) {
			result.push_back(TreeNode(i));
		}
		return result;
	}

}