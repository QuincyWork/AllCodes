#include <gtest/gtest.h>
using namespace std;

/*
��MATLAB�У���һ���ǳ����õĺ��� reshape�������Խ�һ����������Ϊ��һ����С��ͬ���¾��󣬵�������ԭʼ���ݡ�
����һ���ɶ�ά�����ʾ�ľ����Լ�����������r��c���ֱ��ʾ��Ҫ���ع��ľ����������������
�ع���ľ�����Ҫ��ԭʼ���������Ԫ������ͬ���б���˳����䡣
������и���������reshape�����ǿ����Һ���ģ�������µ����ܾ��󣻷������ԭʼ����
ʾ�� 1:
����:
nums =
[[1,2],
 [3,4]]
r = 1, c = 4
���:
[[1,2,3,4]]
����:
�б���nums�Ľ���� [1,2,3,4]���µľ����� 1 * 4 ����, ��֮ǰ��Ԫ��ֵһ��һ������¾���
ʾ�� 2:
����:
nums =
[[1,2],
 [3,4]]
r = 2, c = 4
���:
[[1,2],
 [3,4]]
����:
û�а취�� 2 * 2 ����ת��Ϊ 2 * 4 ���� �������ԭ����
ע�⣺
��������Ŀ�͸߷�Χ�� [1, 100]��
������ r �� c ����������
*/

namespace IV6_1
{
	class Solution {
	public:
		vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
			
			if (nums.size() * nums[0].size() != r * c)
			{
				return nums;
			}

			vector<vector<int>> result;
			vector<int> rows;			
			for (int m = 0; m < nums.size(); ++m)
			{
				for (int n = 0; n < nums[0].size(); ++n)
				{
					rows.push_back(nums[m][n]);
					if (rows.size() == c)
					{
						result.push_back(rows);
						rows.clear();
					}
				}
			}

			return result;
		}
	};

	TEST(Interview, matrixReshape)
	{
		Solution s;
		auto data = vector < vector<int>>{ {1,2},{3,4} };
		auto result = s.matrixReshape(data,1,4);
		result = s.matrixReshape(data, 2, 4);
	}
}