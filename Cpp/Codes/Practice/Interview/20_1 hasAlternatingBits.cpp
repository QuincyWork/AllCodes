#include <gtest/gtest.h>
using namespace std;

namespace IV20_1
{
	/*
	给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。
	示例 1:
	输入: 5
	输出: True
	解释:
	5的二进制数是: 101
	示例 2:
	输入: 7
	输出: False
	解释:
	7的二进制数是: 111
	示例 3:
	输入: 11
	输出: False
	解释:
	11的二进制数是: 1011
	 示例 4:
	输入: 10
	输出: True
	解释:
	10的二进制数是: 1010
	*/

	class Solution {
	public:
		bool hasAlternatingBits(int n) {

			int pre = n % 2;
			n /= 2;

			while (n > 0)
			{
				int cur = n % 2;
				if (cur == pre)
				{
					break;
				}

				pre = cur;
				n /= 2;
			}

			return n == 0;
		}
	};

	TEST(Interview, hasAlternatingBits)
	{
		// 1
		// 2
		// 3 
		// 4
		// 5
		// 6
		Solution s;
		ASSERT_TRUE(s.hasAlternatingBits(1));
		ASSERT_TRUE(s.hasAlternatingBits(2));
		ASSERT_FALSE(s.hasAlternatingBits(3));
		ASSERT_FALSE(s.hasAlternatingBits(4));
		ASSERT_TRUE(s.hasAlternatingBits(5));
		ASSERT_FALSE(s.hasAlternatingBits(6));
		ASSERT_FALSE(s.hasAlternatingBits(7));
	}
}