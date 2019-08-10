#include <gtest/gtest.h>
using namespace std;

namespace IV3
{
	class Solution {
	public:
		int search(vector<int>& nums, int target) {

			int pos = -1;
			int left = 0;
			int right = nums.size() - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (nums[mid] == target)
				{
					pos = mid;
					break;
				}
				else if (nums[mid] > target)
				{
					right = mid-1;
				}
				else
				{
					left = mid+1;
				}
			}

			return pos;
		}
	};

	TEST(Interview, search)
	{
		Solution s;
		vector<int> v = { -1,0,3,5,9,12 };
		ASSERT_EQ(s.search(v, 9), 4);

		v = { -1,0,3,5,9,12 };
		ASSERT_EQ(s.search(v, 2), -1);

		v = { 1 };
		ASSERT_EQ(s.search(v, 1), 0);

		v = { 26 };
		ASSERT_EQ(s.search(v, 51), -1);
	}
}