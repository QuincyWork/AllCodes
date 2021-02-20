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

		if (input.empty()) {
			return tree;
		}

		// 分割字符串
		std::vector<std::string> values;
		std::size_t current, prev = 0;
		auto source = input;
		while (true) {
			
			current = source.find(',',prev);
			if (current != std::string::npos) {
				values.push_back(source.substr(prev, current - prev));
				prev = current + 1;
			}
			else {
				values.push_back(source.substr(prev));
				break;
			}
		}
	
		// 构造二叉树
		std::list<TreeNode*> list;
		auto root = new TreeNode(std::atol(values[0].c_str()));
		list.push_back(root);
		nodes.push_back(root); // 缓存以便释放

		for (size_t i = 1; i < values.size();) {

			auto parent = list.front();
			list.pop_front();
			
			// 对应左子节点
			if (values[i] != "null") {
				parent->left = new TreeNode(std::atol(values[i].c_str()));
				list.push_back(parent->left);
				nodes.push_back(parent->left); // 缓存以便释放
			}
			++i;

			// 对应右子节点
			if (i < values.size() && values[i] != "null") {
				parent->right = new TreeNode(std::atol(values[i].c_str()));
				list.push_back(parent->right);
				nodes.push_back(parent->right); // 缓存以便释放
			}
			++i;
		}

		return tree;
	}

	// 从Tree转字符串
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
				list.push_back(top->left);
				list.push_back(top->right);
			}
			else {
				// 处理连续多个null
				std::string temp = "null,";
				while (!list.empty() && !list.front()) {

					list.pop_front();
					temp += "null,";
				}

				// 末尾全是null的丢弃
				if (!list.empty()) {
					result += temp;
				}
			}
		}
		result.pop_back();

		return result;
	}

private:
	std::vector<TreeNode*> nodes;
};