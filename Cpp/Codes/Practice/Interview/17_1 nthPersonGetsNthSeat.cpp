#include <gtest/gtest.h>
using namespace std;

namespace IV17_1
{
	/*
	有 n 位乘客即将登机，飞机正好有 n 个座位。第一位乘客的票丢了，他随便选了一个座位坐下。
	剩下的乘客将会：
	如果他们自己的座位还空着，就坐到自己的座位上，
	当他们自己的座位被占用时，随机选择其他座位
	第 n 位乘客坐在自己的座位上的概率是多少？
 
	示例 1：
	输入：n = 1
	输出：1.00000
	解释：第一个人只会坐在自己的位置上。
	示例 2：
	输入: n = 2
	输出: 0.50000
	解释：在第一个人选好座位坐下后，第二个人坐在自己的座位上的概率是 0.5。
	*/



	class Solution {
	public:
		double nthPersonGetsNthSeat(int n) {

			/*
			很容易想到，如果第一个人正好坐在自己的位置，那么之后所有的人都会坐在自己的位置。
			如果第一个人正好坐在第n个人的位置，那么第n个人没可能坐在自己的位置。
			如果第一个人坐在除了自己位置以及第n个人的位置之外的任何位置，情况就如同n-1个座位情况。
			*/

			vector<double> dp(n,1);
			for (int i = 2; i <= n; ++i)
			{
				dp[i-1] = (1.0 / i) + (i-2) * dp[i - 2] / i;
			}

			return dp[n-1];
		}
	};

	TEST(Interview, nthPersonGetsNthSeat)
	{
		Solution s;
		ASSERT_EQ(s.nthPersonGetsNthSeat(1), 1);
		ASSERT_EQ(s.nthPersonGetsNthSeat(2), 0.5);
		ASSERT_EQ(s.nthPersonGetsNthSeat(3), 0.5);
		ASSERT_EQ(s.nthPersonGetsNthSeat(4), 0.5);
		ASSERT_EQ(s.nthPersonGetsNthSeat(5), 0.5);
	}
}