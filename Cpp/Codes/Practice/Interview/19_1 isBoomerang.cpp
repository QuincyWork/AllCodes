#include <gtest/gtest.h>
using namespace std;

namespace IV19_1
{
	/*
	�����ڶ���Ϊһ�������㣬��Щ�������ͬ�Ҳ���һ��ֱ���ϡ�
	����ƽ������������ɵ��б��ж���Щ���Ƿ���Թ��ɻ����ڡ�

	ʾ�� 1��
	���룺[[1,1],[2,3],[3,2]]
	�����true
	ʾ�� 2��
	���룺[[1,1],[2,2],[3,3]]
	�����false

	��ʾ��
	points.length == 3
	points[i].length == 2
	0 <= points[i][j] <= 100
	*/

	class Solution {
	public:
		bool isBoomerang(vector<vector<int>>& points) {

			// �����������һ��ֱ����ʱ������x1-x2 = x2-x3 && y1-y2 = y2-y3			
			if ((points[0][0] == points[1][0] && points[0][1] == points[1][1]) ||
				(points[1][0] == points[2][0] && points[1][1] == points[2][1]) ||
				(points[0][0] == points[2][0] && points[0][1] == points[2][1]))
			{
				return false;
			}

			return ((points[1][0] - points[0][0]) * (points[2][1] - points[0][1]) !=
				    (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]));
		}
	};

	TEST(Interview, isBoomerang)
	{
		Solution s;
		vector<vector<int>> d = { {1,1},{2,3},{3,2} };
		ASSERT_TRUE(s.isBoomerang(d));

		d = { {1,1},{2,2},{3,3} };
		ASSERT_FALSE(s.isBoomerang(d));

		d = { {0,0},{1,1},{1,1} };
		ASSERT_FALSE(s.isBoomerang(d));
	}
}