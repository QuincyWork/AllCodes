#include <gtest/gtest.h>
using namespace std;

namespace IV25_2
{
	/*
	打乱一个没有重复元素的数组。

	示例:
	// 以数字集合 1, 2 和 3 初始化数组。
	int[] nums = {1,2,3};
	Solution solution = new Solution(nums);

	// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
	solution.shuffle();

	// 重设数组到它的初始状态[1,2,3]。
	solution.reset();

	// 随机返回数组[1,2,3]打乱后的结果。
	solution.shuffle();
	*/

	class Solution {
	public:
		Solution(vector<int>& nums) {
			_nums = nums;
		}

		/** Resets the array to its original configuration and return it. */
		vector<int> reset() {
			return _nums;
		}

		/** Returns a random shuffling of the array. */
		vector<int> shuffle() {

			vector<int> temp(_nums.size(),-1);
			vector<int> result;

			for (int i = 0; i < temp.size(); ++i)
			{
				int pos = rand() % temp.size();
				if (temp[pos] != -1)
				{
					for (int j = 1; j < temp.size(); ++j)
					{
						if (temp[(pos + j) % temp.size()] == -1)
						{
							pos = (pos + j) % temp.size();
							break;
						}
					}
				}
				
				if (temp[pos] == -1)
				{
					result.push_back(_nums[pos]);
					temp[pos] = pos;
				}
			}

			return result;
		}

		vector<int> _nums;
	};

	/**
	 * Your Solution object will be instantiated and called as such:
	 * Solution* obj = new Solution(nums);
	 * vector<int> param_1 = obj->reset();
	 * vector<int> param_2 = obj->shuffle();
	 */

	TEST(Interview, shuffle)
	{
		Solution s(vector<int>{1,2,3});
		s.reset();
		s.shuffle();
	}
}