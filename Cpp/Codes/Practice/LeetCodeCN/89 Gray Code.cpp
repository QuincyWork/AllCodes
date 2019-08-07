#include <gtest/gtest.h>
using namespace std;

namespace LC89
{
	class Solution {
	public:
		vector<int> grayCode(int n) {

			vector<int> result = {0};
			int value = 0;
			int base = 1;
			int pos = n;
			while (pos > 0)
			{				
				value |= base;
				base <<= 1;
				pos--;
				result.push_back(value);
			}

			pos = n;
			base = 1;
			while (pos > 1)
			{
				value ^= base;
				base <<= 1;
				pos--;
				result.push_back(value);
			}

			return result;
		}
	};

	TEST(LeetCodeCN, tGrayCode)
	{
		Solution s;		
		auto result = s.grayCode(2);
		ASSERT_EQ(result.size(), 4);

		result = s.grayCode(3);
		ASSERT_EQ(result.size(), 6);
	}
}