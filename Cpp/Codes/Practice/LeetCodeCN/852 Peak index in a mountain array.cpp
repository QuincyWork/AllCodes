#include <gtest\gtest.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& A) 
{
	int PreValue = -1;
	int Pos = 0;
	for (size_t i=0; i<A.size(); ++i)
	{
		if (A[i] > PreValue)
		{
			PreValue = A[i];
		}
		else
		{
			Pos = i - 1;
			break;
		}
	}

	return Pos;
}

TEST(LeetCodeCN, tPeakIndexInMountainArray)
{
	ASSERT_EQ(peakIndexInMountainArray(vector<int>{0, 1, 0}), 1);
	ASSERT_EQ(peakIndexInMountainArray(vector<int>{0, 2, 1, 0}), 1);
}