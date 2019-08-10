#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

/*
实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

示例 1：
输入: "Hello"
输出: "hello"
示例 2：
输入: "here"
输出: "here"
示例 3：
输入: "LOVELY"
输出: "lovely"

*/

namespace IV7_1
{
	class Solution {
	public:
		string toLowerCase(string str) {
						
			transform(str.begin(), str.end(), str.begin(), [](int c) {
				if (c >= 'A' && c <= 'Z') {
					c += 'a' - 'A';
				}
				return c;
			});

			return str;
		}
	};

	TEST(Interview, toLowerCase)
	{
		Solution s;
		ASSERT_EQ(s.toLowerCase("Hello"), "hello");
		ASSERT_EQ(s.toLowerCase("here"), "here");
		ASSERT_EQ(s.toLowerCase("LOVELY"), "lovely");
		ASSERT_EQ(s.toLowerCase("123LOVELY"), "123lovely");
	}

}