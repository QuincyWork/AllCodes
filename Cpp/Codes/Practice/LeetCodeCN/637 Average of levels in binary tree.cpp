#include <gtest\gtest.h>
#include <numeric>
using namespace std;

namespace 
{

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {

		vector<double> result;
		vector<vector<int>> cache;
		averageOfLevels(root, 0, cache);

		for (auto& v : cache)
		{
			if (!v.empty())
			{
				long long sum = accumulate(v.begin(), v.end(), (long long)0);
				result.push_back( (double)sum / v.size());
			}
		}

		return result;
	}

	void averageOfLevels(TreeNode* root, int level, vector<vector<int>>& result)
	{
		if (root)
		{
			if (result.size() <= level)
			{
				result.push_back(vector<int>());
			}
			
			result[level].push_back(root->val);
			
			averageOfLevels(root->left, level + 1, result);
			averageOfLevels(root->right, level + 1, result);
		}		
	}
};

TEST(LeetCodeCN, tAverageOfLevels)
{
	Solution s;
	TreeNode nodes[] = { 3,9,20,15,7 };
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	nodes[2].left = &nodes[3];
	nodes[2].right = &nodes[4];


	auto result = s.averageOfLevels(nodes);

}

}