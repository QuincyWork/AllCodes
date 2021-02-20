#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;

namespace LC697
{
	/*
	给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。

	你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

	示例 1：

	输入：[1, 2, 2, 3, 1]
	输出：2
	解释：
	输入数组的度是2，因为元素1和2的出现频数最大，均为2.
	连续子数组里面拥有相同度的有如下所示:
	[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
	最短连续子数组[2, 2]的长度为2，所以返回2.
	示例 2：

	输入：[1,2,2,3,1,4,2]
	输出：6
 

	提示：

	nums.length 在1到 50,000 区间范围内。
	nums[i] 是一个在 0 到 49,999 范围内的整数。

	*/

	class Solution {
	public:
		int findShortestSubArray(vector<int>& nums) {

			struct item {
				int count;
				int begin;
				int end;
			};

			unordered_map<int, item> cache;
			for(size_t i=0; i<nums.size(); ++i){
				
				auto& data = cache[nums[i]];
				if (data.count == 0) {
					data.begin = data.end = i;
				}
				else {
					data.end = i;
				}
				data.count++;
			}

			int result = 0, count = 0;
			for_each(cache.begin(), cache.end(), [&](const auto& v) {
				
				auto size = v.second.end - v.second.begin + 1;
				if (v.second.count > count) {
					count = v.second.count;
					result = size;
				}
				else if ((v.second.count == count) && size < result) {
					result = size;
				}
			});

			return result;
		}

		int findShortestSubArray1(vector<int>& nums) {
			
			// 由于nums.length 在1到 50,000 区间范围内，用uint16_t可以装下
			unordered_map<int, pair<int,uint32_t>> cache;
			for (size_t i = 0; i < nums.size(); ++i) {

				auto& data = cache[nums[i]];
				if (data.first == 0) {
					data.second = ((uint32_t)i << 8) | i;
				}
				else {
					data.second = (data.second & 0xff) | ((uint32_t)i << 8);
				}
				data.first++;
			}

			int result = 0, count = 0;
			for_each(cache.begin(), cache.end(), [&](const auto& v) {

				auto size = ((v.second.second & 0xff00) >> 8) - (v.second.second & 0xff) + 1;
				if (v.second.first > count) {
					count = v.second.first;
					result = size;
				}
				else if ((v.second.first == count) && size < result) {
					result = size;
				}
			});

			return result;
		}
	};

	TEST(LeetCodeCN, findShortestSubArray)
	{
		Solution s;
		ASSERT_EQ(s.findShortestSubArray1(vector<int>{ 1, 2, 2, 3, 1 }), 2);

		ASSERT_EQ(s.findShortestSubArray1(vector<int>{ 1, 2, 2, 3, 1, 4, 2 }), 6);

	}
}