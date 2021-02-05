#pragma once
#include <vector>
#include <Common/Tree.h>

namespace TreeData
{
	
	std::vector<TreeNode> Data(std::initializer_list<int> list) {

		std::vector<TreeNode> result;
		for (auto& i : list) {
			result.push_back(TreeNode(i));
		}
		return result;
	}

}