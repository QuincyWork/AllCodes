#include <gtest/gtest.h>
#include <set>
#include <stack>
using namespace std;

namespace IV3_3
{
	class Solution {
	public:
		vector<vector<int>> findSubsequencesEx(vector<int>& nums) {
			
			if (nums.size() < 2)
			{
				return vector<vector<int>>();
			}

			set<vector<int>> result;
			vector<vector<int>> prev;
			for (int i = 0; i<nums.size(); ++i)
			{				
				int count = prev.size();
				for (int j = 0; j < count; ++j)
				{
					auto v = prev[j];
					v.push_back(nums[i]);
					if (v.size() >= 2)
					{
						result.insert(v);
					}

					prev.push_back(v);
				}

				prev.push_back(vector<int>{nums[i]});
			}
			
			return vector<vector<int>>(result.begin(), result.end());
 		}

		vector<vector<int>> findSubsequences(vector<int>& nums) {
			return vector<vector<int>>();
		}
	};

	TEST(Interview, findSubsequences)
	{
		Solution s;
		auto result = s.findSubsequences(vector<int>{4, 6, 7, 7});
		result = s.findSubsequences(vector<int>{4});
		result = s.findSubsequences(vector<int>{4,5,6,3,2});
	}
}