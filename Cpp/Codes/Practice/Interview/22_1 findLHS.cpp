#include <gtest/gtest.h>
using namespace std;

namespace IV22_1
{
	/*
	��г������ָһ��������Ԫ�ص����ֵ����Сֵ֮��Ĳ��������1��
	���ڣ�����һ���������飬����Ҫ�����п��ܵ����������ҵ���ĺ�г�����еĳ��ȡ�
	ʾ�� 1:
	����: [1,3,2,2,5,2,3,7]
	���: 5
	ԭ��: ��ĺ�г�����ǣ�[3,2,2,2,3].
	˵��: ��������鳤����󲻳���20,000.
	*/

	class Solution {
	public:
		int findLHS(vector<int>& nums) {

			map<int, int> cache;
			for (auto i : nums)
			{
				cache[i]++;
			}

			int result = 0;
			if (cache.size() > 0)
			{
				auto prev = cache.begin();
				auto next = prev;
				next++;

				while(next != cache.end())
				{
					if (next->first == prev->first + 1)
					{
						if (result < next->second + prev->second)
						{
							result = next->second + prev->second;
						}
					}
					prev = next;
					next++;
				}
			}
			
			return result;
		}
	};


	TEST(Interview, findLHS)
	{
		Solution s;
		ASSERT_EQ(s.findLHS(vector<int>{1, 3, 2, 2, 5, 2, 3, 7}), 5);
	}
}