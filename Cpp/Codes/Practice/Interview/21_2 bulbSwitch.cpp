#include <gtest/gtest.h>
using namespace std;

namespace IV21_2
{
	/*
	��ʼʱ�� n �����ݹرա� �� 1 �֣�������еĵ��ݡ� �� 2 �֣�ÿ����������ر�һ�Ρ� �� 3 �֣�ÿ���������л�һ�ο��أ�����ر����������������رգ���
	�� i �֣�ÿ i �������л�һ�ο��ء� ���ڵ� n �֣���ֻ�л����һ�����ݵĿ��ء� �ҳ� n �ֺ��ж��ٸ����ŵĵ��ݡ�
	ʾ��:
	����: 3
	���: 1
	����:
	��ʼʱ, ����״̬ [�ر�, �ر�, �ر�].
	��һ�ֺ�, ����״̬ [����, ����, ����].
	�ڶ��ֺ�, ����״̬ [����, �ر�, ����].
	�����ֺ�, ����״̬ [����, �ر�, �ر�].

	��Ӧ�÷��� 1����Ϊֻ��һ�����ݻ����š�
	*/

	class Solution {
	public:
		int bulbSwitch(int n) {

			vector<bool> cache;
			cache.assign(n, false);

			for (int i = 0; i < n; ++i)
			{
				for (int j = i; j < n; j += i + 1)
				{
					cache[j] = !cache[j];
				}
			}

			return count_if(cache.begin(), cache.end(), [](auto x){ return x;});
		}

		int bulbSwitch1(int n) {

			vector<int> cache;
			cache.assign(n, 0);
			cache[0] = 1;

			for (int i = 2; i <= n; ++i)
			{
				int count = 0;
				for (int j = 1; j <= n; j++)
				{
					if (i % j == 0)
					{
						count++;
					}
				}


				cache[i - 1] = cache[i - 2] + (count % 2 != 0);
			}

			return cache[n - 1];
		}

		int bulbSwitch2(int n) {

			return (int)sqrt(n);
		}
	};

	TEST(Interview, bulbSwitch)
	{
		Solution s;
		ASSERT_EQ(s.bulbSwitch2(1), 1);
		ASSERT_EQ(s.bulbSwitch2(2), 1);
		ASSERT_EQ(s.bulbSwitch2(3), 1);
	}
}