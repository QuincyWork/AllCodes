#include <gtest/gtest.h>
using namespace std;

namespace IV20_1
{
	/*
	����һ��������������������飨���ܰ����ظ����֣�������Ҫ�����Ƿָ�ɼ��������У�����ÿ�����������ٰ�����������������
	�������Ƿ������������ķָ

	ʾ�� 1��
	����: [1,2,3,3,4,5]
	���: True
	����:
	����Էָ�������������������� :
	1, 2, 3
	3, 4, 5

	ʾ�� 2��
	����: [1,2,3,3,4,4,5,5]
	���: True
	����:
	����Էָ�������������������� :
	1, 2, 3, 4, 5
	3, 4, 5

	ʾ�� 3��
	����: [1,2,3,4,4,5]
	���: False

	��ʾ��
	��������鳤�ȷ�ΧΪ [1, 10000]
		*/

	class Solution {
	public:
		bool isPossible(vector<int>& nums) {

			// �����������Ѿ�����õģ����ֻ��Ҫͳ������1�ĸ������������������Ϊ1�ģ�������������

			int count = 0;
			int num = 0;
			for (int i = 1; i < nums.size(); ++i)
			{
				if (nums[i] - nums[i - 1] == 1)
				{
					num++;
				}
				else if(nums[i] - nums[i - 1] > 1)
				{
					num = 0;
				}

				if (num == 2)
				{
					count++;
					num = 0;
					i++;
				}

				if (count > 1)
				{
					break;
				}
			}

			return (count > 1);
		}

	};

	TEST(Interview, isPossible)
	{
		Solution s;

		ASSERT_TRUE(s.isPossible(vector<int>{1, 2, 3, 3, 4, 5}));
		ASSERT_TRUE(s.isPossible(vector<int>{1, 2, 3, 3, 4, 4, 5, 5}));
		ASSERT_FALSE(s.isPossible(vector<int>{1, 2, 3, 4, 4, 5}));
	}
}