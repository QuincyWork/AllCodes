#include<gtest/gtest.h>
using namespace std;

namespace LC443
{
	class Solution {
	public:
		int compress(vector<char>& chars) {

			if (chars.empty())
			{
				return 0;
			}

			int result = 0;
			int output = 0;

			int count = 1;
			int prev = chars[0];			
			for (auto i = 1; i < chars.size(); ++i)
			{
				if (chars[i] != prev)
				{
					chars[output++] = prev;
					result++;
					if (count > 1)
					{					
						int  base = 1000;	// 1 <= len(chars) <= 1000
						bool contain = false;
						while (base != 0)
						{
							int value = count / base;
							count %= base;
							base /= 10;
							if (value > 0)
							{
								contain = true;
							}	

							if (contain)
							{
								chars[output++] = value + '0';
								result++;
							}							
						}								
					}
					
					prev = chars[i];
					count = 0;
				}

				count++;
			}

			chars[output++] = prev;
			result++;
			if (count > 1)
			{
				int  base = 1000;	// 1 <= len(chars) <= 1000						
				bool contain = false;
				while (base != 0)
				{
					int value = count / base;
					count %= base;
					base /= 10;
					if (value > 0)
					{
						contain = true;
					}

					if (contain)
					{
						chars[output++] = value + '0';
						result++;
					}
				}
			}

			return result;
		}
	};

	TEST(LeetCodeCN, tCompress)
	{
		Solution s;
		vector<char> data = {'a','a','b','b','c','c','c' };
		int count = s.compress(data);
		ASSERT_EQ(count, 6);
		data = {};
		count = s.compress(data);
		ASSERT_EQ(count, 0);
		data = {'a'};
		count = s.compress(data);
		ASSERT_EQ(count, 1);
		data = { 'a','a','a','a','a','a','a','a','a','a'};
		count = s.compress(data);
		ASSERT_EQ(count, 3);	
		data = { 'a','a','b','a','b','b','b','d','c','b','b','a' };
		count = s.compress(data);
		ASSERT_EQ(count,11);
	}
}