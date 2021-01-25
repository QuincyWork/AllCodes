#include <gtest/gtest.h>
using namespace std;

namespace IV20_1
{
	/*
	����һ����������������Ƿ�Ϊ����λ�������������仰˵���������Ķ����������ڵ�����λ��������ȡ�
	ʾ�� 1:
	����: 5
	���: True
	����:
	5�Ķ���������: 101
	ʾ�� 2:
	����: 7
	���: False
	����:
	7�Ķ���������: 111
	ʾ�� 3:
	����: 11
	���: False
	����:
	11�Ķ���������: 1011
	 ʾ�� 4:
	����: 10
	���: True
	����:
	10�Ķ���������: 1010
	*/

	class Solution {
	public:
		bool hasAlternatingBits(int n) {

			int pre = n % 2;
			n /= 2;

			while (n > 0)
			{
				int cur = n % 2;
				if (cur == pre)
				{
					break;
				}

				pre = cur;
				n /= 2;
			}

			return n == 0;
		}
	};

	TEST(Interview, hasAlternatingBits)
	{
		// 1
		// 2
		// 3 
		// 4
		// 5
		// 6
		Solution s;
		ASSERT_TRUE(s.hasAlternatingBits(1));
		ASSERT_TRUE(s.hasAlternatingBits(2));
		ASSERT_FALSE(s.hasAlternatingBits(3));
		ASSERT_FALSE(s.hasAlternatingBits(4));
		ASSERT_TRUE(s.hasAlternatingBits(5));
		ASSERT_FALSE(s.hasAlternatingBits(6));
		ASSERT_FALSE(s.hasAlternatingBits(7));
	}
}