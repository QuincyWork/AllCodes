#include <gtest\gtest.h>
#include <stack>
#include <numeric>
using namespace std;

int scoreOfParentheses(string S) 
{
	int result = 0;
	stack<int> data;
	for (auto v : S)
	{
		if (v == '(')
		{
			data.push('(');
		}
		else
		{
			int t = data.top();
			data.pop();			
			if (t == '(')
			{
				data.push(1);
			}
			else
			{
				int prev = data.top();
				data.pop();
				while (prev != '(')
				{
					t += prev;
					prev = data.top();
					data.pop();
				}

				data.push(2 * t);
			}
		}
	}

	while (!data.empty())
	{
		result += data.top();
		data.pop();
	}

	return result;
}

TEST(LeetCodeCN, tScoreOfParentheses)
{
	ASSERT_EQ(scoreOfParentheses("()"), 1);
	ASSERT_EQ(scoreOfParentheses("()()"), 2);
	ASSERT_EQ(scoreOfParentheses("(())"), 2);
	ASSERT_EQ(scoreOfParentheses("(()(()))"), 6);
}