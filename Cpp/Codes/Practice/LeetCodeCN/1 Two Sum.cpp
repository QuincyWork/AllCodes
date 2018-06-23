#include <gtest\gtest.h>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
	bool find = false;	
	vector<int> result;

	for (size_t i = 0; i < nums.size(); ++i)
	{
		int value = nums[i];
		for (size_t j = i+1; j < nums.size(); ++j)
		{						
			if (value + nums[j] == target)
			{
				result.assign({ (int)i,(int)j });
				return result;
			}
		}
	}
	
	return result;
}

TEST(LeetCodeCN, tTwoSum)
{	
	auto result = twoSum(vector<int>{2,7,11,15}, 9);
	ASSERT_FALSE(result.empty());
	
	result = twoSum(vector<int>{2, -1, 30, -4, 8, 12}, 5);
	ASSERT_TRUE(result.empty());

	result = twoSum(vector<int>{}, 0);
	ASSERT_TRUE(result.empty());
}