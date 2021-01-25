#include <gtest/gtest.h>
using namespace std;

namespace PI_0101
{
	/*
	实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

	示例 1：

	输入: s = "leetcode"
	输出: false


	示例 2：

	输入: s = "abc"
	输出: true


	限制：

		0 <= len(s) <= 100
		如果你不使用额外的数据结构，会很加分。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/is-unique-lcci
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/

	class Solution {
	public:
		bool isUnique(string astr) {

			bool result = true;
			bool cached[100] = { false };
			for (auto i : astr)
			{
				if (cached[i - '0'])
				{
					result = false;
					break;
				}

				cached[i - '0'] = true;
			}

			return result;
		}

		// 采用插入排序的变种，判断是否有相同的项
		bool isUnique1(string astr) {

			bool result = true;
			for (int i = 1; i < astr.length(); ++i)
			{
				int v = astr[i];
				int j = i - 1;
				while (j >= 0 && astr[j] > v)
				{
					astr[j + 1] = astr[j];
					--j;
				}

				if (j >=0 && (v == astr[j]))
				{
					result = false;
					break;
				}

				astr[j + 1] = v;
			}
			
			return result;
		}

	};

	TEST(Book1, isUnique)
	{
		Solution s;
		ASSERT_FALSE(s.isUnique("leetcode"));
		ASSERT_TRUE(s.isUnique("abc"));

		ASSERT_FALSE(s.isUnique1("leetcode"));
		ASSERT_TRUE(s.isUnique1("abc"));
	}
}

