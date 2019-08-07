#include <gtest/gtest.h>
using namespace std;

/*
�� i ���˵�����Ϊ people[i]��ÿ�Ҵ����Գ��ص��������Ϊ limit��
ÿ�Ҵ�����ͬʱ�����ˣ�����������Щ�˵�����֮�����Ϊ limit��
�����ص�ÿһ�����������С������(��֤ÿ���˶��ܱ�����)��

ʾ�� 1��
���룺people = [1,2], limit = 3
�����1
���ͣ�1 �Ҵ��� (1, 2)
ʾ�� 2��
���룺people = [3,2,2,1], limit = 3
�����3
���ͣ�3 �Ҵ��ֱ��� (1, 2), (2) �� (3)
ʾ�� 3��
���룺people = [3,5,3,4], limit = 5
�����4
���ͣ�4 �Ҵ��ֱ��� (3), (3), (4), (5)
��ʾ��
1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
*/

namespace IV6_2
{
	class Solution {
	public:
		
		// ����������
		int numRescueBoatsEx(vector<int>& people, int limit) {

			sort(people.begin(), people.end());
			int count = 0;
			int right = people.size() - 1;
			int left = 0;
			while (right >= left)
			{
				int rv = people[right--];
				while (left <= right)
				{
					int lv = people[left];
					if (rv + lv > limit)
					{
						break;
					}

					left++;
				}

				count++;
			}

			return count;
		}

		// ����������
		int numRescueBoats(vector<int>& people, int limit) {

			sort(people.begin(), people.end());
			int count = 0;
			int right = people.size() - 1;
			int left = 0;
			while (right > left)
			{
				int rv = people[right--];
				if (rv + people[left] <= limit)
				{
					left++;
				}

				count++;
			}

			if (right == left)
			{
				count++;
			}

			return count;
		}
	};

	TEST(Interview, numRescueBoats)
	{
		Solution s;
		ASSERT_EQ(s.numRescueBoats(vector<int>{1, 2}, 3), 1);
		ASSERT_EQ(s.numRescueBoats(vector<int>{3, 2, 2, 1}, 3), 3);
		ASSERT_EQ(s.numRescueBoats(vector<int>{3, 5, 3, 4}, 5), 4);
		ASSERT_EQ(s.numRescueBoats(vector<int>{1, 2, 1, 1, 1, 2, 3, 1, 2, 2, 3, 1}, 3), 7);
	}
}