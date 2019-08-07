#include <gtest/gtest.h>
using namespace std;

/*
����һ�������� 0 �� 1 ��ɵĶ�ά���� grid�������ҳ��߽�ȫ���� 1 ��ɵ���� ������ �����񣬲����ظ��������е�Ԫ����������������ڣ��򷵻� 0��

ʾ�� 1��
���룺grid = [[1,1,1],[1,0,1],[1,1,1]]
�����9
ʾ�� 2��
���룺grid = [[1,1,0,0]]
�����1

��ʾ��
1 <= grid.length <= 100
1 <= grid[0].length <= 100
grid[i][j] Ϊ 0 �� 1
*/

namespace IV8_2
{
	class Solution {
	public:
		int largest1BorderedSquare(vector<vector<int>>& grid) {

			int n = grid.size(), m = grid[0].size();
			vector<vector<int>> sum_r(n + 1, vector<int>(m + 1, 0));
			vector<vector<int>> sum_c(m + 1, vector<int>(n + 1, 0));

			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					sum_r[i][j] = sum_r[i][j - 1] + grid[i - 1][j - 1];

			for (int j = 1; j <= m; j++)
				for (int i = 1; i <= n; i++)
					sum_c[j][i] = sum_c[j][i - 1] + grid[i - 1][j - 1];

			for (int len = min(n, m); len >= 1; len--) {
				for (int i = 0; i < n - len + 1; i++)
					for (int j = 0; j < m - len + 1; j++) {
						int x = i + len - 1, y = j + len - 1;
						if (sum_r[i + 1][y + 1] - sum_r[i + 1][j] == len
							&& sum_r[x + 1][y + 1] - sum_r[x + 1][j] == len
							&& sum_c[j + 1][x + 1] - sum_c[j + 1][i] == len
							&& sum_c[y + 1][x + 1] - sum_c[y + 1][i] == len)
							return len * len;
					}
			}
			return 0;
		}
	};
}