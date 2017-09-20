#include <gtest/gtest.h>
#include <algorithm>
#include <math.h>
#include <Common/util.h>
using namespace std;

class MinimumTimeDifference
{
public:
	int findMinDifference(vector<string>& timePoints) 
	{
		sort(timePoints.begin(), timePoints.end());
		int minDiff = numeric_limits<int>::max();
		int length = timePoints.size();
		for (int i = 0; i < length; ++i)
		{
			int diff = abs(
				diffMinute(
					timePoints[(i-1+length) % length],
					timePoints[i]));
			diff = min(diff, 24 * 60 - diff);
			if (diff < minDiff)
			{
				minDiff = diff;
			}
		}

		return minDiff;
	}

	int diffMinute(string A, string B)
	{
		char* timeA = (char*)A.c_str();
		char* timeB = (char*)B.c_str();
		timeA[2] = '\0';
		timeB[2] = '\0';

		return (atoi(timeB) - atoi(timeA)) * 60 +
			(atoi(timeB + 3) - atoi(timeA + 3));
	}
};

TEST(LeetCode, tMinimumTimeDifference)
{
	MinimumTimeDifference s;
	vector<string> timePoints;
	timePoints.push_back("23:59");
	timePoints.push_back("00:00");
	ASSERT_EQ(s.findMinDifference(timePoints), 1);

	timePoints.clear();
	timePoints.push_back("00:00");
	timePoints.push_back("23:59");
	timePoints.push_back("00:00");
	ASSERT_EQ(s.findMinDifference(timePoints), 0);

	timePoints.clear();
	timePoints.push_back("05:31");
	timePoints.push_back("22:08");
	timePoints.push_back("00:35");
	ASSERT_EQ(s.findMinDifference(timePoints), 147);

	timePoints.clear();
	timePoints.push_back("17:41");
	timePoints.push_back("22:06");
	timePoints.push_back("20:59");
	timePoints.push_back("17:37");
	timePoints.push_back("04:14");
	ASSERT_EQ(s.findMinDifference(timePoints), 4);
}