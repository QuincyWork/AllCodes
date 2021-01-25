#include <gtest/gtest.h>
using namespace std;

namespace PI_0104
{
	/*
	����һ���ַ�������дһ�������ж����Ƿ�Ϊĳ�����Ĵ�������֮һ��

	���Ĵ���ָ������������һ���ĵ��ʻ���������ָ��ĸ���������С�

	���Ĵ���һ�����ֵ䵱�еĵ��ʡ�



	ʾ��1��

	���룺"tactcoa"
	�����true��������"tacocat"��"atcocta"���ȵȣ�

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/palindrome-permutation-lcci
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
	*/

	class Solution {
	public:
		bool canPermutePalindrome(string s) {

			// ����ֻҪȷ���ַ��������ֻ��һ���ַ�����������������ż����
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