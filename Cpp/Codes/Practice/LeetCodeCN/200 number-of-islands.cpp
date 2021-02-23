#include <gtest/gtest.h>
using namespace std;

namespace LC200
{
	/*
	给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
	岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
	此外，你可以假设该网格的四条边均被水包围。


	示例 1：

	输入：grid = [
	  ["1","1","1","1","0"],
	  ["1","1","0","1","0"],
	  ["1","1","0","0","0"],
	  ["0","0","0","0","0"]
	]
	输出：1
	示例 2：

	输入：grid = [
	  ["1","1","0","0","0"],
	  ["1","1","0","0","0"],
	  ["0","0","1","0","0"],
	  ["0","0","0","1","1"]
	]
	输出：3
 

	提示：

	m == grid.length
	n == grid[i].length
	1 <= m, n <= 300
	grid[i][j] 的值为 '0' 或 '1'
	*/

	class Solution {
	public:
		int numIslands(vector<vector<char>>& grid) {

			const auto n = grid.size();
			const auto m = grid[0].size();
			
			vector<int> data(n*m, 0);
			
			for (size_t i = 0; i < data.size(); ++i) {
				data[i] = i;
			}
			
			size_t count = data.size();
			for (size_t i = 0; i < n; ++i) {
				for (size_t j = 0; j < m; ++j) {

					if (grid[i][j] == '0'){
						count--;
						continue;
					}

					// 和下一列连同
					if ((j < m - 1) && grid[i][j + 1] == '1') {
						connect(data, i*m + j, i*m + j + 1, count);
					}

					// 和下一行连同
					if ((i < n - 1) && grid[i + 1][j] == '1') {
						connect(data, i*m + j, (i + 1)*m + j, count);
					}
				}
			}

			return count;
		}

		int find(vector<int>& data, size_t index) {
			while (data[index] != index) {
				index = data[index];
			}

			return index;
		}

		void connect(vector<int>&data, size_t p, size_t q, size_t& count)
		{
			int rootp = find(data,p);
			int rootq = find(data,q);
			if (rootp == rootq) {
				return;
			}

			data[rootp] = rootq;
			count--;
		}
	};

	TEST(LeetCodeCN, numIslands)
	{
		Solution s;
		ASSERT_EQ(s.numIslands(vector<vector<char>>{
			{'1', '1', '1', '1', '0'},
			{ '1','1','0','1','0' },
			{ '1','1','0','0','0' },
			{ '0','0','0','0','0' }}),1);

		ASSERT_EQ(s.numIslands(vector<vector<char>>{
			{'1', '1', '0', '0', '0'},
			{ '1','1','0','0','0' },
			{ '0','0','1','0','0' },
			{ '0','0','0','1','1' }}), 3);

	}
}