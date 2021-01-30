#include <gtest/gtest.h>
using namespace std;

namespace PI_0101
{
	/*
	ʵ��һ���㷨��ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ��

	ʾ�� 1��

	����: s = "leetcode"
	���: false


	ʾ�� 2��

	����: s = "abc"
	���: true


	���ƣ�

		0 <= len(s) <= 100
		����㲻ʹ�ö�������ݽṹ����ܼӷ֡�

	��Դ�����ۣ�LeetCode��
	���ӣ�https://leetcode-cn.com/problems/is-unique-lcci
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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

		// ���ò�������ı��֣��ж��Ƿ�����ͬ����
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

