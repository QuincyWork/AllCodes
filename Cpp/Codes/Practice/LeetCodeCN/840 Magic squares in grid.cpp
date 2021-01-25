#include <gtest\gtest.h>
using namespace std;

int numMagicSquaresInside(vector<vector<int>>& grid) 
{
	int result = 0;
	vector<int> data(8, 0);
	for (size_t n = 2; n < grid.size(); ++n)
	{
		for (size_t m = 2 ; m < grid[0].size(); ++m)
		{
			data[0] = grid[n - 2][m - 2] + grid[n - 2][m - 1] + grid[n - 2][m];
			data[1] = grid[n - 1][m - 2] + grid[n - 1][m - 1] + grid[n - 1][m];
			data[2] = grid[n][m - 2] + grid[n][m - 1] + grid[n][m];
			data[3] = grid[n - 2][m - 2] + grid[n - 1][m - 2] + grid[n][m - 2];
			data[4] = grid[n - 2][m - 1] + grid[n - 1][m - 1] + grid[n][m - 1];
			data[5] = grid[n - 2][m] + grid[n - 1][m] + grid[n][m];
			data[6] = grid[n - 2][m - 2] + grid[n - 1][m - 1] + grid[n][m];
			data[7] = grid[n - 2][m] + grid[n - 1][m - 1] + grid[n][m - 2];

			if (count(data.begin(),data.end(),data[0]) == data.size())
			{
				result++;
			}
		}
	}

	return result;
}

TEST(LeetCodeCN, tNumMagicSquaresInside)
{
	vector<vector<int>> d1{
		{4, 3, 8, 4},
		{9, 5, 1, 9},
		{2, 7, 6, 2} };
	ASSERT_EQ(numMagicSquaresInside(d1), 1);
}