#include <gtest/gtest.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

namespace LC652
{
	/*
	给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

	两棵树重复是指它们具有相同的结构以及相同的结点值。

	示例 1：

			1
		   / \
		  2   3
		 /   / \
		4   2   4
		   /
		  4
	下面是两个重复的子树：

		  2
		 /
		4
	和

		4
	因此，你需要以列表的形式返回上述重复子树的根结点。
	*/

	//Definition for a binary tree node.
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	};
 
	class Solution {
	public:
		vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

			unordered_set<string> cache;
			unordered_map<string,TreeNode*> result;
			findDuplicateSubtree(root, cache, result);
			vector<TreeNode*> value;
			transform(result.begin(), result.end(), back_inserter(value), [](auto v) {return v.second; });
			return value;
		}

		string findDuplicateSubtree(TreeNode* root, 
			unordered_set<string>& cache,
			unordered_map<string, TreeNode*>& result) {

			if (root == nullptr) {
				return "#";
			}

			auto left = findDuplicateSubtree(root->left, cache, result);
			auto right = findDuplicateSubtree(root->right, cache, result);

			auto current = left + "," + right + "," + std::to_string(root->val);
			if (cache.find(current) != cache.end()) {
				result.insert(make_pair(current, root));
			}
			else {
				cache.insert(current);
			}

			return current;
		}
	};

	TEST(LeetCodeCN, findDuplicateSubtrees)
	{
		Solution s;
		TreeNode data[] = {1,2,3,4,2,4,4};
		data[0].left = &data[1];
		data[0].right = &data[2];
		data[1].left = &data[3];
		data[2].left = &data[4];
		data[2].right= &data[5];
		data[4].left = &data[6];
		auto result = s.findDuplicateSubtrees(data);
	}
}