#include <gtest/gtest.h>
using namespace std;

namespace IV21_3
{
	/*
	������˷����й����������һ��Ӣ�İ������С��Ϸ���������²¿��ɡ�
���յ����� puzzle ���ַ�����ʽ���������һ������ word ��������������������ô���Ϳ��������յף�
���� word �а������� puzzle �ĵ�һ����ĸ��
���� word �е�ÿһ����ĸ������������ puzzle ���ҵ���
���磬������յ������� "abcdefg"����ô������Ϊ�յ׵ĵ����� "faced", "cabbage", �� "baggage"���� "beefed"��������ĸ "a"���Լ� "based"�����е� "s" û�г����������У���
����һ�������� answer�������е�ÿ��Ԫ�� answer[i] ���ڸ����ĵ����б� words �п�����Ϊ�������� puzzles[i] ����Ӧ���յ׵ĵ�����Ŀ��

ʾ����
���룺
words = ["aaaa","asas","able","ability","actt","actor","access"],
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
�����[1,1,3,2,4,0]
���ͣ�
1 �����ʿ�����Ϊ "aboveyz" ���յ� : "aaaa"
1 �����ʿ�����Ϊ "abrodyz" ���յ� : "aaaa"
3 �����ʿ�����Ϊ "abslute" ���յ� : "aaaa", "asas", "able"
2 �����ʿ�����Ϊ "absoryz" ���յ� : "aaaa", "asas"
4 �����ʿ�����Ϊ "actresz" ���յ� : "aaaa", "asas", "actt", "access"
û�е��ʿ�����Ϊ "gaswxyz" ���յף���Ϊ�б��еĵ��ʶ�������ĸ 'g'��
	*/

	class Solution {
	public:
		vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {

			map<char, std::vector<string>> wordCaches;
			for (auto i : words)
			{
				
			}

			vector<int> result(puzzles.size(),0);
			for (auto i : puzzles)
			{
				
			}
		}
	};


}