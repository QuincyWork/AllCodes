#include <gtest/gtest.h>
using namespace std;

/*
返回字符串 text 中按字典序排列最小的子序列，该子序列包含 text 中所有不同字符一次。

示例 1：
输入："cdadabcc"
输出："adbc"
示例 2：
输入："abcd"
输出："abcd"
示例 3：
输入："ecbacba"
输出："eacb"
示例 4：
输入："leetcode"
输出："letcod"

提示：
1 <= text.length <= 1000
text 由小写英文字母组成
*/

namespace IV9_2
{
	class Solution {
	public:
		string smallestSubsequence(string text) {

			string result = "";
			vector<int> count(26);
			vector<int> used(26);
			for (auto ch : text) 
			{
				count[ch - 'a'] ++;
			}

			for (auto ch : text) 
			{
				int v = ch - 'a';
				count[v]--;
				if (used[v]) 
					continue;

				while (!result.empty() && ch < result.back() && count[result.back() - 'a']) 
				{
					used[result.back() - 'a'] = 0;
					result.pop_back();
				}

				used[v] = 1;
				result.push_back(ch);
			}

			return result;
		}
	};

	TEST(Interview, smallestSubsequence)
	{
		Solution s;
		auto r = s.smallestSubsequence("cdadabcc");
	}
}