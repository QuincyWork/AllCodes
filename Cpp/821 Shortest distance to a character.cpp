#include <gtest\gtest.h>
#include <numeric>
#include <queue>

using namespace std;

vector<int> shortestToChar(string S, char C) 
{	
	queue<int> position;
	for (int i = 0; i < S.length(); ++i)
	{
		if (S[i] == C)
		{
			position.push(i);
		}
	}
		
	int next = position.front();
	int begin = -next;
	position.pop();

	vector<int> result;
	for (int i = 0; i < S.length(); ++i)
	{
		if (i > next)
		{		
			begin = next;
			if (!position.empty())
			{				
				next = position.front();
				position.pop();
			}
			else
			{
				next = numeric_limits<int>::max();
			}			
		}

		result.push_back(std::min(i - begin, next - i));
	}
	
	return result;
}

TEST(LeetCodeCN, tShortestToChar)
{
	auto result = shortestToChar("loveleetcode", 'e');
	result = shortestToChar("gtywtbcnowpwibfdgvph", 'i');
}
