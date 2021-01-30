#include <gtest/gtest.h>
using namespace std;

namespace IV24_1
{
	/*
	给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
	*/

	class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {

			vector<vector<int>> result;
			result.push_back(vector<int>());
			if (nums.size() > 0)
			{
				result.push_back(nums);
			}

			for (int i = 0; i < nums.size(); ++i)
			{
				for (int j = i; j < nums.size(); ++j)
				{
					result.push_back(vector<int>(nums.begin()+i, nums.begin() + j + 1));
				}
			}

			return result;
		}

		vector<vector<int>> subsets1(vector<int>& nums) {

			vector<vector<int>> result({ {} });
			if (nums.size() == 0)
			{
				return result;
			}

			vector<int> state(nums.size(), 0);
			vector<int> stateValue(nums.size(), 0);

			int pos = -1;
			do
			{				
				if (pos == -1)
				{
					state[++pos] = 1;
					stateValue[pos] = nums[state[pos]-1];
				}

				result.push_back(vector<int>(stateValue.begin(), stateValue.begin() + pos + 1));
				
				if (state[pos] < nums.size())
				{
					state[pos + 1] = state[pos] + 1;
					stateValue[pos + 1] = nums[state[pos + 1] - 1];
					pos++;
				}
				else if (pos > 0)
				{
					pos--;
					state[pos]++;
					stateValue[pos] = nums[state[pos] - 1];
				}
				else
				{
					break;
				}
			}
			while(true);

			return result;
		}

		void ShowResult2(int State[], int nPos)
		{
			cout << "{";
			for (int i = 0; i < nPos; ++i)
			{
				cout << State[i] << " ";
			}
			cout << "}\n";
		}

		int GenerateOrderSubset(int nSize)
		{
			if (nSize == 0)
			{
				cout << "{}" << endl;
				return 1;
			}

			int nCount = 0;
			int nPos = -1;
			int *State = new int[nSize];
			memset(State, 0, sizeof(int)*nSize);

			do
			{
				nCount++;
				ShowResult2(State, nPos + 1);
				if (nPos == -1)
				{
					State[++nPos] = 1;
					continue;
				}

				if (State[nPos] < nSize) // 递增集合个数
				{
					State[nPos + 1] = State[nPos] + 1;
					nPos++;
				}
				else if (nPos > 0)
				{
					nPos--;
					State[nPos]++;
				}
				else
				{
					break;
				}
			} while (true);

			delete[] State;

			return nCount;
		}
	};

	TEST(Interview, subsets)
	{
		Solution s;
		auto data = s.subsets1(vector<int>{1, 2, 3});

		s.GenerateOrderSubset(5);
	}
}