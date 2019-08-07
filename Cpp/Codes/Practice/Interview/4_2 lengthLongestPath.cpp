#include <gtest/gtest.h>
#include <stack>
using namespace std;

namespace IV4_2
{
	class Solution {
	public:
		int lengthLongestPath(string input) {

			stack<string> parent;
			while (input.length() > 0)
			{
				auto pos = input.find("\\n");
				if (pos != string::npos)
				{
					string current = input.substr(0, pos);
					input = input.substr(pos + 2);
					//if (current.find())
				}
			}
		}
	};
}