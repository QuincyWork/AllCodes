#include <gtest/gtest.h>
using namespace std;

namespace LC88
{
	class Solution {
	public:
		void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {

			vector<int> result;			

			auto pos1 = nums1.begin();
			auto pos2 = nums2.begin();
			while ((pos1 != nums1.begin() + m) && (pos2 != nums2.begin() + n))
			{
				if (*pos1 < *pos2)
				{
					result.push_back(*pos1);
					pos1++;
				}
				else
				{
					result.push_back(*pos2);
					pos2++;
				}
			}

			while (pos1 != nums1.begin() + m)
			{
				result.push_back(*pos1);
				pos1++;
			}
			
			while (pos2 != nums2.begin() + n)
			{
				result.push_back(*pos2);
				pos2++;
			}

			nums1.assign(result.begin(),result.end());
		}

		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

			int pos = m + n;
			while (m > 0 && n > 0)
			{
				if (nums1[m - 1] > nums2[n - 1])
				{
					nums1[pos - 1] = nums1[m - 1];
					--m;
					--pos;
				}
				else
				{
					nums1[pos - 1] = nums2[n - 1];
					--n;
					--pos;
				}
			}

			while (n > 0)
			{
				nums1[pos - 1] = nums2[n - 1];
				--n;
				--pos;
			}
		}
	};

	TEST(LeetCodeCN, tMerge)
	{
		Solution s;
		
		vector<int> v1 = { 1,2,3,0,0,0 };
		vector<int> v2 = { 2,5,6 };
		s.merge(v1, 3, v2, 3);

	}
}