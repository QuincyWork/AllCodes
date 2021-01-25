#include <gtest/gtest.h>
#include <unordered_set>
using namespace std;

namespace IV23_1
{
	/*
	����һ���ǿ����飬������Ԫ��Ϊ a0, a1, a2, �� , an-1������ 0 �� ai < 231 ��
	�ҵ� ai ��aj ������� (XOR) ������������0 �� i,  j < n ��
	������O(n)��ʱ�������������
	ʾ��:
	����: [3, 10, 5, 25, 2, 8]

	���: 28

	����: ���Ľ���� 5 ^ 25 = 28.
	*/

	class Solution {
	public:
		int findMaximumXOR(vector<int>& nums) {

			int res = 0, mask = 0;
			for (int i = 31; i >= 0; --i) 
			{
				mask |= (1 << i);
				unordered_set<int> s;
				for (int num : nums) 
				{
					s.insert(num & mask);
				}

				int t = res | (1 << i);
				for (int prefix : s) 
				{
					if (s.count(t ^ prefix)) 
					{
						res = t;
						break;
					}
				}
			}

			return res;
		}
	};

	TEST(Interview, findMaximumXOR)
	{
		Solution s;
		ASSERT_EQ(s.findMaximumXOR(vector<int>{3, 10, 5, 25, 2, 8}), 28);
	}
}