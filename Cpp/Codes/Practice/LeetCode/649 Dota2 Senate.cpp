#include <gtest\gtest.h>
using namespace std;

static string predictPartyVictory(string senate)
{	
	int banDelta = 0; // > 0 表示需要禁言D的个数，< 0 表示需要禁言R的个数
	int countOfR;
	int countOfD;

	do
	{	
		countOfR = 0;
		countOfD = 0;
		string current;
		for (size_t i = 0; i < senate.length(); ++i)
		{
			if (senate[i] == 'R')
			{
				if (banDelta >= 0)
				{
					current += "R";
					countOfR++;
				}

				banDelta++;
			}
			else
			{
				if (banDelta <= 0)
				{
					current += "D";
					countOfD++;
				}

				banDelta--;
			}
		}

		senate = current;

	} while (countOfR && countOfD);
	
	return (senate[0] == 'R') ? "Radiant" : "Dire";
}

TEST(LeetCode, tPredictPartyVictory)
{
	ASSERT_EQ(predictPartyVictory("RD"),"Radiant");
	ASSERT_EQ(predictPartyVictory("RDD"), "Dire");
	ASSERT_EQ(predictPartyVictory("RDDRDRDDDRDDRRRDR"), "Dire");
}