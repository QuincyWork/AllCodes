#include <gtest/gtest.h>
#include <stack>
using namespace std;

namespace IV3_2
{
	class Solution {
	public:
		bool isValid(string S) {

			if (S.length() % 3 != 0 ||
				S.length() == 0)
			{
				return false;
			}

			if (S[0] != 'a')
			{
				return false;
			}

			stack<char> stack;
			for (auto c : S)
			{
				if (c != 'c')
				{
					stack.push(c);
				}
				else
				{
					bool valid = false;
					if (stack.size() >= 2)
					{
						auto b = stack.top();
						stack.pop();
						auto a = stack.top();
						stack.pop();
						valid = (a == 'a' && b == 'b');
					}

					if (!valid)
					{
						return valid;
					}
				}
			}

			return stack.empty();
		}
	};

	TEST(Interview, isValid)
	{
		Solution s;
		ASSERT_TRUE(s.isValid("aabcbc"));
		ASSERT_TRUE(s.isValid("abcabcababcc"));
		ASSERT_FALSE(s.isValid("abccba"));
		ASSERT_FALSE(s.isValid("cababc"));
		ASSERT_FALSE(s.isValid("aaabba"));
		ASSERT_FALSE(s.isValid(""));
	}
}