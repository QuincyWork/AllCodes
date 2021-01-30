#include <gtest/gtest.h>
using namespace std;

namespace IV19_1
{
	/*
	回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。
	给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。

	示例 1：
	输入：[[1,1],[2,3],[3,2]]
	输出：true
	示例 2：
	输入：[[1,1],[2,2],[3,3]]
	输出：false

	提示：
	points.length == 3
	points[i].length == 2
	0 <= points[i][j] <= 100
	*/

	class Solution {
	public:
		bool isBoomerang(vector<vector<int>>& points) {

			// 如果三个点在一条直线上时，会有x1-x2 = x2-x3 && y1-y2 = y2-y3			
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