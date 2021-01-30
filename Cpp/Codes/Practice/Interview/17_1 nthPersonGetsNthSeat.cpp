#include <gtest/gtest.h>
using namespace std;

namespace IV17_1
{
	/*
	�� n λ�˿ͼ����ǻ����ɻ������� n ����λ����һλ�˿͵�Ʊ���ˣ������ѡ��һ����λ���¡�
	ʣ�µĳ˿ͽ��᣺
	��������Լ�����λ�����ţ��������Լ�����λ�ϣ�
	�������Լ�����λ��ռ��ʱ�����ѡ��������λ
	�� n λ�˿������Լ�����λ�ϵĸ����Ƕ��٣�
 
	ʾ�� 1��
	���룺n = 1
	�����1.00000
	���ͣ���һ����ֻ�������Լ���λ���ϡ�
	ʾ�� 2��
	����: n = 2
	���: 0.50000
	���ͣ��ڵ�һ����ѡ����λ���º󣬵ڶ����������Լ�����λ�ϵĸ����� 0.5��
	*/



	class Solution {
	public:
		double nthPersonGetsNthSeat(int n) {

			/*
			�������뵽�������һ�������������Լ���λ�ã���ô֮�����е��˶��������Լ���λ�á�
			�����һ�����������ڵ�n���˵�λ�ã���ô��n����û���������Լ���λ�á�
			�����һ�������ڳ����Լ�λ���Լ���n���˵�λ��֮����κ�λ�ã��������ͬn-1����λ�����
			*/

			vector<double> dp(n,1);
			for (int i = 2; i <= n; ++i)
			{
				dp[i-1] = (1.0 / i) + (i-2) * dp[i - 2] / i;
			}

			return dp[n-1];
		}
	};

	TEST(Interview, nthPersonGetsNthSeat)
	{
		Solution s;
		ASSERT_EQ(s.nthPersonGetsNthSeat(1), 1);
		ASSERT_EQ(s.nthPersonGetsNthSeat(2), 0.5);
		ASSERT_EQ(s.nthPersonGetsNthSeat(3), 0.5);
		ASSERT_EQ(s.nthPersonGetsNthSeat(4), 0.5);
		ASSERT_EQ(s.nthPersonGetsNthSeat(5), 0.5);
	}
}