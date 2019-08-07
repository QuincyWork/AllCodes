#include <gtest/gtest.h>
using namespace std;

namespace IV4_1
{
	class Solution {
	public:
		int numUniqueEmails(vector<string>& emails) {

			set<string> result;
			for (auto email : emails)
			{
				auto pos = email.find('@');
				if (pos != string::npos)
				{
					string localName = email.substr(0, pos);
					string realmName = email.substr(pos + 1);
					string newName = "";
					for (auto c : localName)
					{
						if (c == '+')
						{
							break;
						}
						else if (c != '.')
						{
							newName += c;
						}
					}
					result.insert(newName + "@" + realmName);
				}
			}

			return result.size();
		}
	};

	TEST(Interview, numUniqueEmails)
	{
		Solution s;
		vector<string> v = { "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com" };
		ASSERT_EQ(s.numUniqueEmails(v), 2);
	}
}