#include <gtest/gtest.h>
using namespace std;

namespace IV17_3
{
	/*
	����һ������ n ������������ nums �� һ��Ŀ��ֵ target���ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ���
	�������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�
	���磬�������� nums = [-1��2��1��-4], �� target = 1.

	�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).
	*/

	class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {

			sort(nums.begin(), nums.end());
			int des = numeric_limits<int>::max();
			int result = 0;
			
			for (int i = 0; i < nums.size(); ++i)
			{
				int left = i + 1;
				int right = nums.size() - 1;
				while (left < right)
				{
					int sum = nums[i] + nums[left] + nums[right];
					if (sum == target)
					{
						return target;
					}
					else if (sum < target)
					{
						if (target - sum < des)
						{
							des = target - sum;
							result = sum;
						}
						left++;
					}
					else
					{
						if (sum - target < des)
						{
							des = sum - target;
							result = sum;
						}
						right--;
					}
				}
			}

			return result;
		}
	};

	TEST(Interview, threeSumClosest)
	{
		Solution s;
		//ASSERT_EQ(s.threeSumClosest());
	}
}