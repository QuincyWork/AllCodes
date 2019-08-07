#include <gtest/gtest.h>
using namespace std;

/*
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����
����Ϊ�ǿ��ַ�����ֻ�������� 1 �� 0��
ʾ�� 1:
����: a = "11", b = "1"
���: "100"
ʾ�� 2:
����: a = "1010", b = "1011"
���: "10101"
*/

namespace IV9_1
{
	class Solution {
	public:
		string addBinary(string a, string b) {
			
			string result = a;
			string add = b;
			if (a.size() < b.size())
			{
				result = b;
				add = a;
			}

			int rpos = result.size() - 1;
			int apos = add.size() - 1;
			int carry = 0;
			while (apos >= 0)
			{
				int v = (result[rpos] == '1') ? 1 : 0;
				v += (add[apos] == '1') ? 1 : 0;
				v += carry;

				carry = v / 2;
				v %= 2;
				result[rpos] = v + '0';

				rpos--;
				apos--;
			}

			while (carry > 0)
			{
				if (rpos < 0)
				{
					result.insert(result.begin(), '0');
					rpos = 0;
				}

				int v = (result[rpos] == '1') ? 1 : 0;
				v += carry;
				carry = v / 2;
				v %= 2;
				result[rpos--] = v + '0';
			}

			return result;
		}
	};

	TEST(Interview, addBinary)
	{
		Solution s;
		auto r = s.addBinary("1010", "1011");
		r = s.addBinary("1", "111");
	}
}