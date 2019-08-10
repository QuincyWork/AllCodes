#include <gtest/gtest.h>
using namespace std;

/*
����һ�������Ǹ����������飬���������ͳ�����п�����������������ߵ���Ԫ�������
ʾ�� 1:
����: [2,2,3,4]
���: 3
����:
��Ч�������:
2,3,4 (ʹ�õ�һ�� 2)
2,3,4 (ʹ�õڶ��� 2)
2,2,3
ע��:
���鳤�Ȳ�����1000��
�����������ķ�ΧΪ [0, 1000]��
*/

namespace IV9_3
{
	class Solution {
	public:
		int triangleNumber1(vector<int>& nums) {

			int count = 0;
			for (int i = 0; i < nums.size(); ++i)
			{
				for (int j = i + 1; j < nums.size(); ++j)
				{
					for (int k = j + 1; k < nums.size(); ++k)
					{
						if (nums[i] + nums[j] > nums[k] &&
							nums[i] + nums[k] > nums[j] &&
							nums[j] + nums[k] > nums[i])
						{
							count++;
						}
					}
				}
			}

			return count;
		}

		int triangleNumber(vector<int>& nums) {

			int count = 0;
			sort(nums.begin(), nums.end());
			for (int i = nums.size() - 1; i >= 2; --i)
			{
				int left = 0, right = i - 1;
				while (left < right) 
				{
					if (nums[left] + nums[right] > nums[i]) 
					{
						count += right - left;
						--right;
					}
					else 
					{
						++left;
					}
				}
			}
			return count;
		}
	};

	TEST(Interview, triangleNumber)
	{
		Solution s;
		auto r = s.triangleNumber(vector<int> {2, 2, 3, 4});
	}
}