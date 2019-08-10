#include <gtest\gtest.h>
using namespace std;

string toLowerCase(string str) 
{
	transform(str.begin(), str.end(), str.begin(), tolower);
	return str;
}

TEST(LeetCodeCN, tToLowerCase)
{
	ASSERT_EQ(toLowerCase("Hello"), "hello");
	ASSERT_EQ(toLowerCase("hero"), "hero");

}