#include <gtest/gtest.h>
using namespace std;

namespace IV17_3
{
	/*
	给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
	返回这三个数的和。假定每组输入只存在唯一答案。
	例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

	与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
	*/

	class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {

			sort(nums.begin(), nums.end());
			int des = numeric_limits<int>::max();
			int result = 0;
			
			for (int i = 0; i < nums.size(); ++i)
			{
				int left = i + 1;
				int right = nums.size() - 1;
				while (left < right)
				{
					int sum = nums[i] + nums[left] + nums[right];
					if (sum == target)
					{
						return target;
					}
					else if (sum < target)
					{
						if (target - sum < des)
						{
							des = target - sum;
							result = sum;
						}
						left++;
					}
					else
					{
						if (sum - target < des)
						{
							des = sum - target;
							result = sum;
						}
						right--;
					}
				}
			}

			return result;
		}
	};

	TEST(Interview, threeSumClosest)
	{
		Solution s;
		//ASSERT_EQ(s.threeSumClosest());
	}
}