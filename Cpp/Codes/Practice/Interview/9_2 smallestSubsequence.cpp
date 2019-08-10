#include <gtest/gtest.h>
using namespace std;

/*
�����ַ��� text �а��ֵ���������С�������У��������а��� text �����в�ͬ�ַ�һ�Ρ�

ʾ�� 1��
���룺"cdadabcc"
�����"adbc"
ʾ�� 2��
���룺"abcd"
�����"abcd"
ʾ�� 3��
���룺"ecbacba"
�����"eacb"
ʾ�� 4��
���룺"leetcode"
�����"letcod"

��ʾ��
1 <= text.length <= 1000
text ��СдӢ����ĸ���
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