#include <gtest/gtest.h>
#include <list>
using namespace std;

/*
дһ�� RecentCounter �����������������
��ֻ��һ��������ping(int t)������ t �����Ժ���Ϊ��λ��ĳ��ʱ�䡣
���ش� 3000 ����ǰ�����ڵ� ping ����
�κδ��� [t - 3000, t] ʱ�䷶Χ֮�ڵ� ping �����ᱻ�������ڣ�������ǰ��ָ t ʱ�̣��� ping��
��֤ÿ�ζ� ping �ĵ��ö�ʹ�ñ�֮ǰ����� t ֵ��

ʾ����
���룺inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
�����[null,1,2,3,3]

��ʾ��
ÿ���������������� 10000 �� ping��
ÿ������������ʹ���ϸ������ t ֵ������ ping��
ÿ�ε��� ping ���� 1 <= t <= 10^9��

*/

namespace IV13_2
{
	class RecentCounter {
	public:
		RecentCounter() {

		}

		int ping(int t) {

			auto it = pings.begin();
			while (it != pings.end())
			{
				if (*it >= t - 3000)
				{
					break;
				}

				it++;
			}

			pings.erase(pings.begin(), it);
			pings.push_back(t);
			return pings.size();
		}

	private:
		list<int> pings;
	};

	TEST(Interview, tRecentCounter)
	{
		RecentCounter s;
		ASSERT_EQ(s.ping(1), 1);
		ASSERT_EQ(s.ping(100), 2);
		ASSERT_EQ(s.ping(3001), 3);
		ASSERT_EQ(s.ping(3002), 3);
	}
}