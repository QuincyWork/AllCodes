#include <gtest/gtest.h>
using namespace std;

namespace PI_0104
{
	/*
	给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

	回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

	回文串不一定是字典当中的单词。



	示例1：

	输入："tactcoa"
	输出：true（排列有"tacocat"、"atcocta"，等等）

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/palindrome-permutation-lcci
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/

	class Solution {
	public:
		bool canPermutePalindrome(string s) {

			// 这里只要确认字符串中最多只有一个字符奇数个，其他都是偶数个
			int cached[255] = { 0 };
			for (auto i : s)
			{
				cached[i]++;
			}

			int count = 0;
			for (auto i : cached)
			{
				if (i % 2 == 1)
				{
					count++;
					if (count > 1)
					{
						break;
					}
				}
			}

			return (count <= 1);
		}
	};

	TEST(Book1, canPermutePalindrome)
	{
		Solution s;
		ASSERT_TRUE(s.canPermutePalindrome("tactcoa"));
	}

}