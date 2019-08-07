#include <gtest\gtest.h>
using namespace std;

namespace LC38
{
	class Solution {
	public:
		string countAndSay(int n) {

			string result = "";
			if (n > 1)
			{
				string prev = countAndSay(n - 1);
				if (!prev.empty())
				{
					int count = 1;
					char value = prev[0];
					for (auto i = 1; i < prev.size(); ++i)
					{
						if (prev[i] == value)
						{
							count++;
						}
						else
						{
							result += (count + '0');
							result += value;

							value = prev[i];
							count = 1;
						}
					}

					result += (count + '0');
					result += value;
				}
			}
			else if (n == 1)
			{
				result = "1";
			}
			
			return result;
		}
	};
	
	TEST(LeetCodeCN,tCountAndSay)
	{
		Solution s;
		string result = s.countAndSay(1);
		ASSERT_EQ(result, "1");
		result = s.countAndSay(2);
		ASSERT_EQ(result, "11");
		result = s.countAndSay(3);
		ASSERT_EQ(result, "21");
		result = s.countAndSay(4);
		ASSERT_EQ(result, "1211");
		result = s.countAndSay(5);
		ASSERT_EQ(result, "111221");
		result = s.countAndSay(6);
		ASSERT_EQ(result, "312211");
		result = s.countAndSay(7);
		ASSERT_EQ(result, "13112221");
	}
}
