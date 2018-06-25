#include <gtest/gtest.h>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
{
	for (auto &v : A)
	{
		size_t length = v.size();
		for (size_t i = 0; i < length / 2; ++i)
		{
			int t = v[length - 1 - i];
			v[length - 1 - i] = v[i] ^ 1;
			v[i] = t ^ 1;
		}

		if (length % 2 != 0)
		{
			v[length / 2] ^= 1;
		}
	}

	return A;
}

TEST(LeetCodeCN, tFlipAndInvertImage)
{
	vector<vector<int>> val1 = { {1, 1, 0},{1, 0, 1},{0, 0, 0} };
	auto result = flipAndInvertImage(val1);

	vector<vector<int>> val2 = { {1, 1, 0, 0},{1, 0, 0, 1},{0, 1, 1, 1},{1, 0, 1, 0} };
	result = flipAndInvertImage(val2);
}
