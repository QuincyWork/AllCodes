#include <gtest/gtest.h>
using namespace std;

namespace IV17_2
{
	/*
	���������е���ʿ���԰���ͼ��ʾ�����ƶ���
 .

	��һ�Σ����ǽ� ����ʿ�� ���ڵ绰�����̵��������ּ�������ͼ��ʾ���ϣ�����������ʿ������ N-1 ����ÿһ�������Ǵ�һ�����ּ�������һ�����ּ���
	ÿ��������һ�����ϣ�������ʿ�ĳ�ʼλ�ã������Ღ��������Ӧ�����֣��ܹ����� N λ���֡�
	���������ַ�ʽ�������ٸ���ͬ�ĺ��룿
	��Ϊ�𰸿��ܴܺ����������ģ 10^9 + 7��


	ʾ�� 1��
	���룺1
	�����10
	ʾ�� 2��
	���룺2
	�����20
	ʾ�� 3��
	���룺3
	�����46

	��ʾ��
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
			
			// �� N = 1 ��ʱ��ֻ��1���߷���ͣ��ԭ��
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