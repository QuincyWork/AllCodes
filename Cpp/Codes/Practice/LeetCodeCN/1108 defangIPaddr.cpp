#include <gtest/gtest.h>
using namespace std;

/*
����һ����Ч�� IPv4 ��ַ address��������� IP ��ַ����Ч���汾��

��ν��Ч�� IP ��ַ����ʵ������ "[.]" ������ÿ�� "."��

ʾ�� 1��

���룺address = "1.1.1.1"
�����"1[.]1[.]1[.]1"

ʾ�� 2��

���룺address = "255.100.50.0"
�����"255[.]100[.]50[.]0"

��ʾ��
	������ address ��һ����Ч�� IPv4 ��ַ

*/

namespace LCN_1108
{
	class Solution {
	public:
		string defangIPaddr(string address) {

			string result;
			for (auto c : address)
			{
				if (c == '.')
				{
					result += "[.]";
				}
				else
				{
					result += c;
				}
			}

			return result;
		}
	};

	TEST(LeetCodeCN, defangIPaddr)
	{
		Solution s;
		ASSERT_EQ(s.defangIPaddr("1.1.1.1"), "1[.]1[.]1[.]1");
	}
}