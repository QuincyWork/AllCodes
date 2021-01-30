#include <gtest/gtest.h>
using namespace std;

namespace PI_0102
{
	/*
	���������ַ��� s1 �� s2�����дһ������ȷ������һ���ַ������ַ��������к��ܷ�����һ���ַ�����

	ʾ�� 1��

	����: s1 = "abc", s2 = "bca"
	���: true


	ʾ�� 2��

	����: s1 = "abc", s2 = "bad"
	���: false


	˵����


		0 <= len(s1) <= 100
		0 <= len(s2) <= 100

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/check-permutation-lcci
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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