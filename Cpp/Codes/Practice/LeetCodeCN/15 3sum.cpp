#include <gtest\gtest.h>
#include <vector>

using namespace std;

namespace LC15
{
	class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {

			vector<vector<int>> result;
			sort(nums.begin(), nums.end());			
			for (int i = 0; i < nums.size(); ++i)
			{
				for (int j = i+1; j < nums.size(); ++j)
				{
					for (int k = j + 1; k < nums.size(); ++k)
					{
						if (nums[i] + nums[j] + nums[k] == 0)
						{
							result.push_back(vector<int>({ nums[i],nums[j],nums[k] }));
						}
					}
				}
			}

			return result;
		}
	};

	TEST(LeetCodeCN, tThreeSum)
	{
		Solution s;
		auto result = s.threeSum(vector<int>({ -1,0,1,2,-1,-4 }));
	}
}
