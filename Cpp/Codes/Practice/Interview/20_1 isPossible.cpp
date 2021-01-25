#include <gtest/gtest.h>
using namespace std;

namespace IV20_1
{
	/*
	输入一个按升序排序的整数数组（可能包含重复数字），你需要将它们分割成几个子序列，其中每个子序列至少包含三个连续整数。
	返回你是否能做出这样的分割？

	示例 1：
	输入: [1,2,3,3,4,5]
	输出: True
	解释:
	你可以分割出这样两个连续子序列 :
	1, 2, 3
	3, 4, 5

	示例 2：
	输入: [1,2,3,3,4,4,5,5]
	输出: True
	解释:
	你可以分割出这样两个连续子序列 :
	1, 2, 3, 4, 5
	3, 4, 5

	示例 3：
	输入: [1,2,3,4,4,5]
	输出: False

	提示：
	输入的数组长度范围为 [1, 10000]
		*/

	class Solution {
	public:
		bool isPossible(vector<int>& nums) {

			// 由于数组是已经排序好的，因而只需要统计相邻1的个数，如果有两个连续为1的，则是满足条件

			int count = 0;
			int num = 0;
			for (int i = 1; i < nums.size(); ++i)
			{
				if (nums[i] - nums[i - 1] == 1)
				{
					num++;
				}
				else if(nums[i] - nums[i - 1] > 1)
				{
					num = 0;
				}

				if (num == 2)
				{
					count++;
					num = 0;
					i++;
				}

				if (count > 1)
				{
					break;
				}
			}

			return (count > 1);
		}

	};

	TEST(Interview, isPossible)
	{
		Solution s;

		ASSERT_TRUE(s.isPossible(vector<int>{1, 2, 3, 3, 4, 5}));
		ASSERT_TRUE(s.isPossible(vector<int>{1, 2, 3, 3, 4, 4, 5, 5}));
		ASSERT_FALSE(s.isPossible(vector<int>{1, 2, 3, 4, 4, 5}));
	}
}