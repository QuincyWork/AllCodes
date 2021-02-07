#pragma once
#include <string>
#include <list>

// Tree结构的定义和初始化

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
	virtual ~Tree()
	{
		clear();
	}

	void clear()
	{
		for (auto& it : nodes) {
			delete it;
		}

		nodes.clear();
	}

	operator TreeNode*() const
	{
		if (nodes.empty()) {
			return nullptr;
		}
		return nodes[0];
	}

	// 从字符串构建tree
	static std::shared_ptr<Tree> toTree(const std::string& input)
	{
		std::shared_ptr<Tree> tree(new Tree());
		auto& nodes = tree->nodes;

		std::size_t current, prev = 0;
		auto source = input + ',';
		current = source.find(',');
		while (current != std::string::npos) {
			
			TreeNode* node = nullptr;
			auto value = source.substr(prev, current - prev);
			if (value != "null") {
				node = new TreeNode(std::atol(value.c_str()));
			}
			nodes.push_back(node);

			// 更新父节点子树
			if (nodes.size() > 1) {
				int parent = (nodes.size() - 2) / 2;
				int delta = (nodes.size() - 2) % 2;
				if (delta == 0) {
					nodes[parent]->left = node;
				}
				else {
					nodes[parent]->right = node;
				}
			}

			prev = current + 1;
			current = source.find(',', prev);
		}

		return tree;
	}

	// 从Tree装字符串
	static std::string toString(TreeNode* root) {
		
		if (!root) {
			return "";
		}

		std::string result;
		std::list<TreeNode*> list;
		list.push_back(root);
		while (!list.empty()) {

			auto top = list.front();
			list.pop_front();
			if (top != nullptr) {
				result += std::to_string(top->val) + ",";
				if (top->left || top->right) {
					list.push_back(top->left);
					list.push_back(top->right);
				}
			}
			else {
				result += "null,";
			}
		}
		result.pop_back();

		return result;
	}

private:
	std::vector<TreeNode*> nodes;
};