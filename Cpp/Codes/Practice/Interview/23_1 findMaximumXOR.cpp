#include <gtest/gtest.h>
#include <unordered_set>
using namespace std;

namespace IV23_1
{
	/*
	给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。
	找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。
	你能在O(n)的时间解决这个问题吗？
	示例:
	输入: [3, 10, 5, 25, 2, 8]

	输出: 28

	解释: 最大的结果是 5 ^ 25 = 28.
	*/

	class Solution {
	public:
		int findMaximumXOR(vector<int>& nums) {

			int res = 0, mask = 0;
			for (int i = 31; i >= 0; --i) 
			{
				mask |= (1 << i);
				unordered_set<int> s;
				for (int num : nums) 
				{
					s.insert(num & mask);
				}

				int t = res | (1 << i);
				for (int prefix : s) 
				{
					if (s.count(t ^ prefix)) 
					{
						res = t;
						break;
					}
				}
			}

			return res;
		}
	};

	TEST(Interview, findMaximumXOR)
	{
		Solution s;
		ASSERT_EQ(s.findMaximumXOR(vector<int>{3, 10, 5, 25, 2, 8}), 28);
	}
}