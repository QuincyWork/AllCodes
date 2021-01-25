#include <gtest/gtest.h>
using namespace std;

namespace PI_0102
{
	/*
	给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

	示例 1：

	输入: s1 = "abc", s2 = "bca"
	输出: true


	示例 2：

	输入: s1 = "abc", s2 = "bad"
	输出: false


	说明：


		0 <= len(s1) <= 100
		0 <= len(s2) <= 100

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/check-permutation-lcci
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
		*/

	class Solution {
	public:
		bool CheckPermutation(string s1, string s2) {
			
			if (s1.length() != s2.length())
			{
				return false;
			}

			bool result = true;
			int count[100] = { 0 };
			for (auto i : s1)
			{
				count[i - '0']++;
			}

			for (auto i : s2)
			{
				if (--count[i - '0'] < 0)
				{
					result = false;
					break;
				}
			}

			return result;
		}
	};

	TEST(Book1, CheckPermutation)
	{
		Solution s;
		ASSERT_TRUE(s.CheckPermutation("abc", "cba"));
		ASSERT_FALSE(s.CheckPermutation("abc", "bad"));
	}
}