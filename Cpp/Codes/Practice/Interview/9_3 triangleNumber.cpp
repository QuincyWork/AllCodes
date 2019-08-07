#include <gtest/gtest.h>
using namespace std;

/*
给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。
示例 1:
输入: [2,2,3,4]
输出: 3
解释:
有效的组合是:
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
注意:
数组长度不超过1000。
数组里整数的范围为 [0, 1000]。
*/

namespace IV9_3
{
	class Solution {
	public:
		int triangleNumber1(vector<int>& nums) {

			int count = 0;
			for (int i = 0; i < nums.size(); ++i)
			{
				for (int j = i + 1; j < nums.size(); ++j)
				{
					for (int k = j + 1; k < nums.size(); ++k)
					{
						if (nums[i] + nums[j] > nums[k] &&
							nums[i] + nums[k] > nums[j] &&
							nums[j] + nums[k] > nums[i])
						{
							count++;
						}
					}
				}
			}

			return count;
		}

		int triangleNumber(vector<int>& nums) {

			int count = 0;
			sort(nums.begin(), nums.end());
			for (int i = nums.size() - 1; i >= 2; --i)
			{
				int left = 0, right = i - 1;
				while (left < right) 
				{
					if (nums[left] + nums[right] > nums[i]) 
					{
						count += right - left;
						--right;
					}
					else 
					{
						++left;
					}
				}
			}
			return count;
		}
	};

	TEST(Interview, triangleNumber)
	{
		Solution s;
		auto r = s.triangleNumber(vector<int> {2, 2, 3, 4});
	}
}