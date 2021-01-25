#include <gtest/gtest.h>
using namespace std;

/*
������ˮ̯�ϣ�ÿһ������ˮ���ۼ�Ϊ 5 ��Ԫ��
�˿��Ŷӹ�����Ĳ�Ʒ�������˵� bills ֧����˳��һ�ι���һ����
ÿλ�˿�ֻ��һ������ˮ��Ȼ�����㸶 5 ��Ԫ��10 ��Ԫ�� 20 ��Ԫ��������ÿ���˿���ȷ���㣬Ҳ����˵��������ÿλ�˿�����֧�� 5 ��Ԫ��
ע�⣬һ��ʼ����ͷû���κ���Ǯ��
������ܸ�ÿλ�˿���ȷ���㣬���� true �����򷵻� false ��
ʾ�� 1��
���룺[5,5,5,10,20]
�����true
���ͣ�
ǰ 3 λ�˿�������ǰ�˳����ȡ 3 �� 5 ��Ԫ�ĳ�Ʊ��
�� 4 λ�˿����������ȡһ�� 10 ��Ԫ�ĳ�Ʊ�������� 5 ��Ԫ��
�� 5 λ�˿���������һ�һ�� 10 ��Ԫ�ĳ�Ʊ��һ�� 5 ��Ԫ�ĳ�Ʊ��
�������пͻ����õ�����ȷ�����㣬����������� true��
ʾ�� 2��
���룺[5,5,10]
�����true
ʾ�� 3��
���룺[10,10]
�����false
ʾ�� 4��
���룺[5,5,10,10,20]
�����false
���ͣ�
ǰ 2 λ�˿�������ǰ�˳����ȡ 2 �� 5 ��Ԫ�ĳ�Ʊ��
���ڽ������� 2 λ�˿ͣ�������ȡһ�� 10 ��Ԫ�ĳ�Ʊ��Ȼ�󷵻� 5 ��Ԫ��
�������һλ�˿ͣ������޷��˻� 15 ��Ԫ����Ϊ��������ֻ������ 10 ��Ԫ�ĳ�Ʊ��
���ڲ���ÿλ�˿Ͷ��õ�����ȷ�����㣬���Դ��� false��

��ʾ��
0 <= bills.length <= 10000
bills[i] ���� 5 ���� 10 ���� 20
*/

namespace IV12_1
{
	class Solution {
	public:
		bool lemonadeChange1(vector<int>& bills) {

			bool result = false;
			int bill5 = 0;
			int bill10 = 0;

			for (auto v : bills)
			{
				while (v > 5 && (bill5 || bill10))
				{
					if (v > 10 && bill10)
					{
						v -= 10;
						--bill10;
					}
					else if(bill5)
					{
						v -= 5;
						--bill5;
					}
					else
					{
						break;
					}
				}

				if (v > 5)
				{
					result = false;
					break;
				}
			}

			return result;
		}

		bool lemonadeChange(vector<int>& bills) {

			bool result = true;
			int bill5 = 0;
			int bill10 = 0;

			for (auto v : bills)
			{
				if (v == 5)
				{
					bill5++;
				}
				else if (v == 10)
				{
					bill5--;
					bill10++;
				}
				else if (bill10)
				{
			
					bill10--;
					bill5--;
				}
				else
				{
					bill5 -= 3;
				}

				if (bill5 < 0)
				{
					result = false;
					break;
				}
			}

			return result;
		}
	};

	TEST(Interview, lemonadeChange)
	{
		Solution s;
		ASSERT_TRUE(s.lemonadeChange(vector<int>{ 5,5,5,10,20 }));
		ASSERT_TRUE(s.lemonadeChange(vector<int>{ 5,5,10 }));
		ASSERT_FALSE(s.lemonadeChange(vector<int>{ 10,10 }));
		ASSERT_FALSE(s.lemonadeChange(vector<int>{ 5,5,10,10,20 }));
	}
}