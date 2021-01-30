#include <gtest/gtest.h>
using namespace std;

namespace IV22_1
{
	/*
	和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
	现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
	示例 1:
	输入: [1,3,2,2,5,2,3,7]
	输出: 5
	原因: 最长的和谐数组是：[3,2,2,2,3].
	说明: 输入的数组长度最大不超过20,000.
	*/

	class Solution {
	public:
		int findLHS(vector<int>& nums) {

			map<int, int> cache;
			for (auto i : nums)
			{
				cache[i]++;
			}

			int result = 0;
			if (cache.size() > 0)
			{
				auto prev = cache.begin();
				auto next = prev;
				next++;

				while(next != cache.end())
				{
					if (next->first == prev->first + 1)
					{
						if (result < next->second + prev->second)
						{
							result = next->second + prev->second;
						}
					}
					prev = next;
					next++;
				}
			}
			
			return result;
		}
	};


	TEST(Interview, findLHS)
	{
		Solution s;
		ASSERT_EQ(s.findLHS(vector<int>{1, 3, 2, 2, 5, 2, 3, 7}), 5);
	}
}