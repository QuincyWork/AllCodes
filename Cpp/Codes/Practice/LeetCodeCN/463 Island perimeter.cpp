#include <gtest\gtest.h>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {

	int count = 0;
	for (size_t i = 0; i < grid.size(); ++i){

		for (size_t j = 0; j < grid[0].size(); ++j) {
			
			if (grid[i][j] == 1){
				count += 4;

				if (i > 0 && grid[i - 1][j] == 1){
					count -= 2;
				}

				if (j > 0 && grid[i][j - 1] == 1){
					count -= 2;
				}
			}
		}
	}

	return count;
}

TEST(LeetCodeCN, tIslandPerimeter)
{
	vector<vector<int>> v = { {0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{1, 1, 0, 0} };
	ASSERT_EQ(islandPerimeter(v), 16);
}