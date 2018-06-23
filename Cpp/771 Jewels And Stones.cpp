#include <gtest\gtest.h>
#include <unordered_set>
using namespace std;


int numJewelsInStones(string J, string S) 
{
	unordered_set<char> tblJewel(J.begin(),J.end());
	int count = 0;

	for (auto i : S)
	{
		if (tblJewel.find(i) != tblJewel.end())
		{
			count++;
		}
	}

	return count;
}

int numJewelsInStones2(string J, string S)
{
	vector<bool> tblJewel(256, false);
	int count = 0;
	for (auto i : J)
	{
		tblJewel[i] = true;
	}

	for (auto i : S)
	{
		if (tblJewel[i])
		{
			count++;
		}
	}

	return count;
}

TEST(LeetCodeCN, tNumJewelsInStones)
{
	ASSERT_EQ(numJewelsInStones2("aA", "aAAbbbb"), 3);
	ASSERT_EQ(numJewelsInStones2("z", "ZZ"), 0);
	ASSERT_EQ(numJewelsInStones2("", ""), 0);
	ASSERT_EQ(numJewelsInStones2("Abcdf", "afca1wdfAffaFDab"), 8);
}