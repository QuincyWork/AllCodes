#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

namespace IV1
{
	class Solution {
	public:
		int bagOfTokensScore(vector<int>& tokens, int P) {
						
			for (int i = 0; i < tokens.size(); ++i)
			{
				for (int j = i+1; j < tokens.size(); ++j)
				{
					if (tokens[j] < tokens[i])
					{
						int temp = tokens[i];
						tokens[i] = tokens[j];
						tokens[j] = temp;
					}
				}
			}
			
			int score = 0;
			int power = P;
			int left = 0;
			int right = tokens.size() - 1;
			while (left <= right && (power >= tokens[left]))
			{
				while (left <= right && power >= tokens[left])
				{
					power -= tokens[left];
					left++;
					score++;
				}

				if (score > 0 && (right > left) && (tokens[right] > tokens[left]))
				{
					power += tokens[right];
					right--;
					score--;
				}
			}

			return score;
		}
	};

	TEST(Interview, bagOfTokensScore)
	{
		Solution s;
		vector<int> v = { 100 };
		ASSERT_EQ(s.bagOfTokensScore(v, 50), 0);

		v = { 100,200 };
		ASSERT_EQ(s.bagOfTokensScore(v, 150), 1);

		v = { 100,200,300,400 };
		ASSERT_EQ(s.bagOfTokensScore(v, 200), 2);

		v = { 100,100,200,300,400 };
		ASSERT_EQ(s.bagOfTokensScore(v, 300), 3);

		v = { 26 };
		ASSERT_EQ(s.bagOfTokensScore(v, 51), 1);
	}
}

