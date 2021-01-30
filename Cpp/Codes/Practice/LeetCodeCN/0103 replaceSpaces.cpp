#include <gtest/gtest.h>
using namespace std;

namespace PI_0103
{
	/*
	URL������дһ�ַ��������ַ����еĿո�ȫ���滻Ϊ%20���ٶ����ַ���β�����㹻�Ŀռ��������ַ�������֪���ַ����ġ���ʵ�����ȡ���ע����Javaʵ�ֵĻ�����ʹ���ַ�����ʵ�֣��Ա�ֱ���������ϲ�������

	ʾ��1:

	 ���룺"Mr John Smith    ", 13
	 �����"Mr%20John%20Smith"


	ʾ��2:

	 ���룺"               ", 5
	 �����"%20%20%20%20%20"


	��ʾ��


		�ַ���������[0, 500000]��Χ�ڡ�

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/string-to-url-lcci
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
	*/

	class Solution {
	public:
		string replaceSpaces(string S, int length) {

			int count = 0;
			for (int i=0; i<length; ++i)
			{
				if (S[i] == ' ')
				{
					count++;
				}
			}

			if (count > 0)
			{
				int pos = length + count * 2 - 1;
				for (int i = length - 1; i >= 0; --i)
				{
					if (S[i] == ' ')
					{
						S[pos--] = '0';
						S[pos--] = '2';
						S[pos--] = '%';
					}
					else
					{
						S[pos--] = S[i];
					}
				}
			}

			S.resize(length + count * 2);
			return S;
		}
	};

	TEST(Book1, replaceSpaces)
	{
		Solution s;
		ASSERT_EQ(s.replaceSpaces("Mr John Smith    ", 13), "Mr%20John%20Smith");
		ASSERT_EQ(s.replaceSpaces("               ", 5), "%20%20%20%20%20");
	}

}