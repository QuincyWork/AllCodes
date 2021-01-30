#include <gtest/gtest.h>
using namespace std;

namespace PI_0103
{
	/*
	URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

	示例1:

	 输入："Mr John Smith    ", 13
	 输出："Mr%20John%20Smith"


	示例2:

	 输入："               ", 5
	 输出："%20%20%20%20%20"


	提示：


		字符串长度在[0, 500000]范围内。

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/string-to-url-lcci
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/

	class Solution {
	public:
		string replaceSpaces(string S, int length) {

			int count = 0;
			for (int i=0; i<length; ++i)
			{
				if (S[i] == ' ')
				{
					count++;
				}
			}

			if (count > 0)
			{
				int pos = length + count * 2 - 1;
				for (int i = length - 1; i >= 0; --i)
				{
					if (S[i] == ' ')
					{
						S[pos--] = '0';
						S[pos--] = '2';
						S[pos--] = '%';
					}
					else
					{
						S[pos--] = S[i];
					}
				}
			}

			S.resize(length + count * 2);
			return S;
		}
	};

	TEST(Book1, replaceSpaces)
	{
		Solution s;
		ASSERT_EQ(s.replaceSpaces("Mr John Smith    ", 13), "Mr%20John%20Smith");
		ASSERT_EQ(s.replaceSpaces("               ", 5), "%20%20%20%20%20");
	}

}