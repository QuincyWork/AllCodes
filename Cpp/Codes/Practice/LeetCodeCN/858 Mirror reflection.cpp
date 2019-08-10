#include <gtest\gtest.h>
using namespace std;

int mirrorReflection(int p, int q) 
{
	int count = 1;
	int sum = q;
	int result = -1;

	while (true)
	{
		if (sum % p == 0)
		{
			if (count % 2 == 0)
			{
				result = 2;
				break;
			}

			result = 1;
			if ((sum / p) % 2 == 0)
			{
				result = 0;
			}

			break;
		}

		count++;
		sum += q;
	}

	return result;
}

TEST(LeetCodeCN, tMirrorReflection)
{
	ASSERT_EQ(mirrorReflection(2, 1), 2);
	ASSERT_EQ(mirrorReflection(3, 1), 1);
}