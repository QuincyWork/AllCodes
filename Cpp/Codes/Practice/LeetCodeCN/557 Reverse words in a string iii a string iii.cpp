#include <gtest\gtest.h>

using namespace std;

string reverseWords(string s) 
{
	string result;
	auto next = s.rbegin();
	auto it = next;
	for (; it != s.rend(); ++it)
	{
		if (*it == ' ')
		{
			string value(next,it);
			result = " " + value + result;
			next = ++it;
		}
	}
	
	if (it != next)
	{
		string value(next,it);
		result = value + result;
	}
	
	return result;
}

string reverseWords1(string s)
{	
	auto next = s.rbegin();
	auto it = next;
	for (; it != s.rend(); ++it)
	{
		if (*it == ' ')
		{
			std::reverse(next, it);
			next = ++it;
		}
	}

	if (it != next)
	{
		std::reverse(next, it);
	}

	return s;
}


TEST(LeetCodeCN, tReverseWords)
{
	auto result = reverseWords1("Let's take LeetCode contest");


}