#include <gtest/gtest.h>
using namespace std;

/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。


示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

namespace ALGO_STR
{
	// 判断回文字符串
	bool isPalindrome(string& s, int b, int e)
	{
		while (e > b && s[b] == s[e])
		{
			b++;
			e--;
		}

		return b >= e;
	}

	// 暴力方法
	// 两层遍历所有子字符串，判断是否是回文字符串，并记录最长的子串
	string longestPalindrome1(string s) {

		string result;
		if (s.empty())
		{
			return result;
		}

		result = s.substr(0,1);
		for (size_t i = 0; i < s.length(); ++i)
		{
			for (size_t j = i + 1; j < s.length(); ++j)
			{
				// 判读子串s[i,j]是否是回文字符串
				if (isPalindrome(s, i, j) && 
					(j-i+1) > result.length())
				{
					result = s.substr(i, j - i + 1);
				}
			}
		}

		return result;
	}

	// 中心扩展法
	// 回文中心的两侧互为镜像，因此，回文可以从它的中心展开，并且只有 2n - 1个这样的中心。
	// 字母数为偶数的回文的中心可以处于两字母之间（例如 ：“abba” 的中心在两个b之间），时间复杂度也只有O(n​2​​)
	string longestPalindrome2(string s) {

		string result;
		for (size_t i = 0; i < s.length(); ++i)
		{
			// 奇数中心
			size_t n = 0;
			while (n <= i && 
				   n < s.length() - i && 
				   s[i-n] == s[i+n])
			{
				n++;
			}
			n = 2 * n - 1;

			// 偶数中心
			size_t m = 0;
			while (m <= i &&
				m < s.length() - i - 1 &&
				s[i - m] == s[i + m + 1])
			{
				m++;
			}
			m = 2 * m;

			// 取最大长度
			if (m > n)
			{
				n = m;
			}
			
			if (n > result.length())
			{
				result = s.substr(i - (n - 1) / 2, n);
			}
		}

		return result;
	}

	// 动态规划
	// 使用dp[i][j]保存数据 dp(i,j)=(dp(i+1,j−1) and s[​i]​​==s[​j]​​),来避免重复计算
	// dp[i][j] = true  i=j
	// dp[i][j] = s[i] == s[j]  j-i = 1  两个
	// dp[i][j] = s[i] == s[j]  j-i = 2  三个
	// dp[i][j] = s[i] == s[j] && s[i+1][j-1]  j-i > 2
	string longestPalindrome3(string s) {

		string result;
		if (s.empty())
		{
			return result;
		}

		vector<vector<bool>> dp(s.length(), vector<bool>(s.length(),false));

		for (size_t j = 0; j < s.length(); ++j)
		{
			for (size_t i = 0; i <= j; i++)
			{
				dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i+1][j-1]);
				if (dp[i][j] && j-i+1 > result.length())
				{
					result = s.substr(i, j - i + 1);
				}
			}
		}

		return result;
	}

	// Manacher法
	// 主要思想是中心扩展法
	// 不过提供了一种巧妙地办法，将长度为奇数的回文串和长度为偶数的回文串一起考虑
	// 具体做法是，在原字符串的每个相邻两个字符中间插入一个分隔符，同时在首尾也要添加一个分隔符，分隔符的要求是不在原串中出现，一般情况下可以用#号。
	string longestPalindrome4(string s) {

		return "";
	}

	
	// 测试用例
	TEST(Algo, longestPalindrome)
	{
		// 暴力
		// ""
		ASSERT_EQ(longestPalindrome1(""), "");

		// "a"
		ASSERT_EQ(longestPalindrome1("a"), "a");

		// "aa"
		ASSERT_EQ(longestPalindrome1("aa"), "aa");

		// "aaa"
		ASSERT_EQ(longestPalindrome1("aaa"), "aaa");

		// "aba"
		ASSERT_EQ(longestPalindrome1("aba"), "aba");

		// "abba"
		ASSERT_EQ(longestPalindrome1("abba"), "abba");

		// "abc"
		ASSERT_EQ(longestPalindrome1("abc"), "a");

		// "babad"
		ASSERT_EQ(longestPalindrome1("babad"), "bab");

		// "cbbd"
		ASSERT_EQ(longestPalindrome1("cbbd"), "bb");


		// 中心扩展
		// ""
		ASSERT_EQ(longestPalindrome2(""), "");

		// "a"
		ASSERT_EQ(longestPalindrome2("a"), "a");

		// "aa"
		ASSERT_EQ(longestPalindrome2("aa"), "aa");

		// "aaa"
		ASSERT_EQ(longestPalindrome2("aaa"), "aaa");

		// "aba"
		ASSERT_EQ(longestPalindrome2("aba"), "aba");

		// "abba"
		ASSERT_EQ(longestPalindrome2("abba"), "abba");

		// "abc"
		ASSERT_EQ(longestPalindrome2("abc"), "a");

		// "babad"
		ASSERT_EQ(longestPalindrome2("babad"), "bab");

		// "cbbd"
		ASSERT_EQ(longestPalindrome2("cbbd"), "bb");


		// 动态规划
		// ""
		ASSERT_EQ(longestPalindrome3(""), "");

		// "a"
		ASSERT_EQ(longestPalindrome3("a"), "a");

		// "aa"
		ASSERT_EQ(longestPalindrome3("aa"), "aa");

		// "aaa"
		ASSERT_EQ(longestPalindrome3("aaa"), "aaa");

		// "aba"
		ASSERT_EQ(longestPalindrome3("aba"), "aba");

		// "abba"
		ASSERT_EQ(longestPalindrome3("abba"), "abba");

		// "abc"
		ASSERT_EQ(longestPalindrome3("abc"), "a");

		// "babad"
		ASSERT_EQ(longestPalindrome3("babad"), "bab");

		// "cbbd"
		ASSERT_EQ(longestPalindrome3("cbbd"), "bb");



	}

}