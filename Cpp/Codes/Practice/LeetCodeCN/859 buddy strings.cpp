#include <gtest\gtest.h>
#include <unordered_set>

using namespace std;

bool buddyStrings(string A, string B) 
{
	if (A.size() != B.size())
	{
		return false;
	}

	bool result = false;
	if (A == B)
	{
		unordered_set<char> data(A.begin(),A.end());		
		result = data.size() < A.size();
	}
	else
	{
		vector<int> data;
		for (size_t i = 0; i < A.size(); ++i)
		{
			if (A[i] != B[i])
			{
				data.push_back(A[i] - B[i]);
			}
		}

		if ((data.size() == 2) && 
			(data[0] + data[1] == 0))
		{
			result = true;
		}
	}

	return result;
}

TEST(LeetCodeCN, tBuddyStrings)
{
	ASSERT_TRUE(buddyStrings("ab", "ba"));
	ASSERT_TRUE(buddyStrings("aa", "aa"));
	ASSERT_FALSE(buddyStrings("ab", "ab"));
	ASSERT_TRUE(buddyStrings("aaaaaaabc", "aaaaaaacb"));
	ASSERT_FALSE(buddyStrings("", "aa"));

}