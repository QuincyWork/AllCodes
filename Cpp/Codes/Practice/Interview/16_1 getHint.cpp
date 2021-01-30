#include <gtest/gtest.h>
#include <set>
using namespace std;

namespace IV16_1
{
	/*
	�����ں���������� �����֣�Bulls and Cows����Ϸ����д��һ��������������Ѳ¡�ÿ�����²�������һ����ʾ���������ж���λ���ֺ�ȷ��λ�ö��¶��ˣ���Ϊ��Bulls��, ��ţ�����ж���λ���ֲ¶��˵���λ�ò��ԣ���Ϊ��Cows��, ��ţ����������ѽ��������ʾ�����£�ֱ���³��������֡�
	��д��һ�������������ֺ����ѵĲ²���������ʾ�ĺ������� A ��ʾ��ţ���� B ��ʾ��ţ��
	��ע���������ֺ����ѵĲ²��������ܺ����ظ����֡�
	ʾ�� 1:
	����: secret = "1807", guess = "7810"

	���: "1A3B"

	����: 1 ��ţ�� 3 ��ţ����ţ�� 8����ţ�� 0, 1 �� 7��
	ʾ�� 2:
	����: secret = "1123", guess = "0111"

	���: "1A1B"

	����: ���Ѳ²����еĵ�һ�� 1 �ǹ�ţ���ڶ���������� 1 �ɱ���Ϊ��ţ��
	˵��: ����Լ����������ֺ����ѵĲ²�����ֻ�������֣��������ǵĳ�����Զ��ȡ�
	*/

	class Solution {
	public:
		string getHint(string secret, string guess) {

			int countA = 0;
			int countB = 0;

			multiset<char> cache;
			cache.insert(secret.begin(), secret.end());
			string left;
			
			for (int i = 0; i < guess.length(); ++i)
			{
				auto itfind = cache.find(guess[i]);
				if (itfind != cache.end())
				{
					if (secret[i] == guess[i])
					{
						countA++;
						cache.erase(itfind);
					}
					else
					{
						left += guess[i];
					}
				}
			}

			for (auto i : left)
			{
				auto itfind = cache.find(i);
				if (itfind != cache.end())
				{
					countB++;
					cache.erase(itfind);
				}
			}

			stringstream result;
			result << countA << "A" << countB << "B";
			return result.str();
		}
	};

	TEST(Interview, getHint)
	{
		Solution s;
		ASSERT_EQ(s.getHint("1807", "7810"), "1A3B");
		ASSERT_EQ(s.getHint("1123", "0111"), "1A1B");
		ASSERT_EQ(s.getHint("1122", "1222"), "3A0B");
	}
}