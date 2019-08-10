#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

/*
ʵ�ֺ��� ToLowerCase()���ú�������һ���ַ������� str���������ַ����еĴ�д��ĸת����Сд��ĸ��֮�󷵻��µ��ַ�����

ʾ�� 1��
����: "Hello"
���: "hello"
ʾ�� 2��
����: "here"
���: "here"
ʾ�� 3��
����: "LOVELY"
���: "lovely"

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