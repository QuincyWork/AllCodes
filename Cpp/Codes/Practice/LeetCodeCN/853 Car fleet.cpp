#include <gtest\gtest.h>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) 
{
	int result = 0;
	double preTime = 0;

	vector<pair<int, int>> data;
	for (size_t i = 0; i < position.size(); ++i)
	{
		data.push_back(make_pair(position[i], speed[i]));
	}

	sort(data.begin(), data.end(), 
		[](auto& a, auto& b) -> bool { return a.first > b.first; });

	for (size_t i = 0; i < data.size(); ++i)
	{
		double currentTime = double(target - data[i].first) / data[i].second;
		if (currentTime > preTime)
		{
			result++;
			preTime = currentTime;
		}
	}

	return result;
}

TEST(LeetCodeCN, tCarFleet)
{
	ASSERT_EQ(carFleet(12, vector<int>{10, 8, 0, 5, 3}, vector<int>{2, 4, 1, 1, 3}), 3);
	ASSERT_EQ(carFleet(10, vector<int>{6,8}, vector<int>{3,2}), 2);
}

