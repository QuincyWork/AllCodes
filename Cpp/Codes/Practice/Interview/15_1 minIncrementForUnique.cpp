#include <gtest/gtest.h>
#include <unordered_set>
using namespace std;

/*
给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。
返回使 A 中的每个值都是唯一的最少操作次数。
示例 1:
输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
示例 2:
输入：[3,2,1,2,1,7]
输出：6
解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
提示：
0 <= A.length <= 40000
0 <= A[i] < 40000
*/

namespace IV15_1
{
	class Solution {
	public:
		int minIncrementForUnique1(vector<int>& A) {

			int result = 0;
			sort(A.begin(), A.end());
			unordered_set<int> sets;
			for (auto i : A)
			{
				while (sets.find(i) != sets.end())
				{
					i++;
					result++;
				}

				sets.insert(i);
			}

			return result;
		}

		int minIncrementForUnique(vector<int>& A) {

			int result = 0;
			sort(A.begin(), A.end());
			for (int i = 1; i < A.size(); ++i)
			{
				if (A[i] <= A[i - 1])
				{					
					result += A[i - 1] - A[i] + 1;
					A[i] = A[i-1] + 1;					
				}
			}

			return result;
		}
	};

	TEST(Interview, minIncrementForUnique)
	{
		Solution s;
		ASSERT_EQ(s.minIncrementForUnique(vector<int>{1, 2, 2}), 1);
		ASSERT_EQ(s.minIncrementForUnique(vector<int>{3, 2, 1, 2, 1, 7}), 6);
	}
}