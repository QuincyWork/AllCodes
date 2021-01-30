#include <gtest/gtest.h>
using namespace std;

namespace IV21_2
{
	/*
	初始时有 n 个灯泡关闭。 第 1 轮，你打开所有的灯泡。 第 2 轮，每两个灯泡你关闭一次。 第 3 轮，每三个灯泡切换一次开关（如果关闭则开启，如果开启则关闭）。
	第 i 轮，每 i 个灯泡切换一次开关。 对于第 n 轮，你只切换最后一个灯泡的开关。 找出 n 轮后有多少个亮着的灯泡。
	示例:
	输入: 3
	输出: 1
	解释:
	初始时, 灯泡状态 [关闭, 关闭, 关闭].
	第一轮后, 灯泡状态 [开启, 开启, 开启].
	第二轮后, 灯泡状态 [开启, 关闭, 开启].
	第三轮后, 灯泡状态 [开启, 关闭, 关闭].

	你应该返回 1，因为只有一个灯泡还亮着。
	*/

	class Solution {
	public:
		int bulbSwitch(int n) {

			vector<bool> cache;
			cache.assign(n, false);

			for (int i = 0; i < n; ++i)
			{
				for (int j = i; j < n; j += i + 1)
				{
					cache[j] = !cache[j];
				}
			}

			return count_if(cache.begin(), cache.end(), [](auto x){ return x;});
		}

		int bulbSwitch1(int n) {

			vector<int> cache;
			cache.assign(n, 0);
			cache[0] = 1;

			for (int i = 2; i <= n; ++i)
			{
				int count = 0;
				for (int j = 1; j <= n; j++)
				{
					if (i % j == 0)
					{
						count++;
					}
				}


				cache[i - 1] = cache[i - 2] + (count % 2 != 0);
			}

			return cache[n - 1];
		}

		int bulbSwitch2(int n) {

			return (int)sqrt(n);
		}
	};

	TEST(Interview, bulbSwitch)
	{
		Solution s;
		ASSERT_EQ(s.bulbSwitch2(1), 1);
		ASSERT_EQ(s.bulbSwitch2(2), 1);
		ASSERT_EQ(s.bulbSwitch2(3), 1);
	}
}