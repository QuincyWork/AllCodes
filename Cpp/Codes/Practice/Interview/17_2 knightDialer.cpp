#include <gtest/gtest.h>
using namespace std;

namespace IV17_2
{
	/*
	国际象棋中的骑士可以按下图所示进行移动：
 .

	这一次，我们将 “骑士” 放在电话拨号盘的任意数字键（如上图所示）上，接下来，骑士将会跳 N-1 步。每一步必须是从一个数字键跳到另一个数字键。
	每当它落在一个键上（包括骑士的初始位置），都会拨出键所对应的数字，总共按下 N 位数字。
	你能用这种方式拨出多少个不同的号码？
	因为答案可能很大，所以输出答案模 10^9 + 7。


	示例 1：
	输入：1
	输出：10
	示例 2：
	输入：2
	输出：20
	示例 3：
	输入：3
	输出：46

	提示：
	1 <= N <= 5000
	*/

	class Solution {
	public:
		int knightDialer(int N) {

			vector<vector<int>> dp(N, vector<int>(10));
			int MOD = 1000000007;

			vector<vector<int>> next {
						{4 , 6 },//0
						{6 , 8 },//1
						{7 , 9 },//2
						{4 , 8 },//3
						{3 , 9, 0 },//4
						{ },//5
						{1 , 7 ,0 },//6
						{2 , 6 },//7
						{1 , 3 },//8
						{2 , 4 },//9
			};
			
			// 当 N = 1 的时候，只有1种走法：停在原地
			dp[0].assign(10, 1);
			for (int i = 1; i < N; ++i)
			{
				for (int j = 0; j <= 9; ++j)
				{
					for (int k = 0; k < next[j].size(); k++)
					{
						dp[i][j] += dp[i - 1][next[j][k]];
						dp[i][j] %= MOD;
					}
				}
			}

			long ans = 0;
			for (int i = 0; i < 10; i++) {
				ans += dp[N-1][i];
			}
			ans %= MOD;

			return (int)ans;
		}
	};

	TEST(Interview, knightDialer)
	{
		Solution s;
		ASSERT_EQ(s.knightDialer(1), 10);
		ASSERT_EQ(s.knightDialer(2), 20);
		ASSERT_EQ(s.knightDialer(3), 46);
	}
}