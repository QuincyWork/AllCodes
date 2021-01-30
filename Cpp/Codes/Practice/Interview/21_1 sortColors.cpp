#include <gtest/gtest.h>
using namespace std;

namespace IV21_1
{
	/*
	����һ��������ɫ����ɫ����ɫ��һ�� n ��Ԫ�ص����飬ԭ�ض����ǽ�������ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳�����С�
	�����У�����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ��
	ע��:
	����ʹ�ô�����е����������������⡣
	ʾ��:
	����: [2,0,2,1,1,0]
	���: [0,0,1,1,2,2]
	���ף�
	һ��ֱ�۵Ľ��������ʹ�ü������������ɨ���㷨��
	���ȣ����������0��1 �� 2 Ԫ�صĸ�����Ȼ����0��1��2��������д��ǰ���顣
	�������һ����ʹ�ó����ռ��һ��ɨ���㷨��
	*/

	class Solution {
	public:
		
		void sortColors(vector<int>& nums) {

			int count[3] = { 0 };
			for (auto i : nums)
			{
				count[i]++;
			}

			int pos = 0;
			for(int i = 0; i<3; ++i)
			{
				while (count[i]-- > 0)
				{
					nums[pos++] = i;
				}
			}
		}
	};

	TEST(Interview, sortColors)
	{
		Solution s;
		auto d = vector<int>{ 2, 0, 2, 1, 1, 0 };
		s.sortColors(d);

		d = vector<int>();
		s.sortColors(d);

		d = vector<int>{0};
		s.sortColors(d);

		d = vector<int>{ 2,1,0 };
		s.sortColors(d);
	}
}