#include <gtest/gtest.h>
#include <unordered_set>
using namespace std;

/*
������������ A��ÿ�� move ��������ѡ������ A[i]����������� 1��
����ʹ A �е�ÿ��ֵ����Ψһ�����ٲ���������
ʾ�� 1:
���룺[1,2,2]
�����1
���ͣ�����һ�� move ���������齫��Ϊ [1, 2, 3]��
ʾ�� 2:
���룺[3,2,1,2,1,7]
�����6
���ͣ����� 6 �� move ���������齫��Ϊ [3, 4, 1, 2, 5, 7]��
���Կ��� 5 �λ� 5 �����µ� move �����ǲ����������ÿ��ֵΨһ�ġ�
��ʾ��
0 <= A.length <= 40000
0 <= A[i] < 40000
*/

namespace IV15_1
{
	class Solution {
	public:
		int minIncrementForUnique1(vector<int>& A) {

			int result = 0;
			sort(A.begin(), A.end());
			unordered_set<int> sets;
			for (auto i : A)
			{
				while (sets.find(i) != sets.end())
				{
					i++;
					result++;
				}

				sets.insert(i);
			}

			return result;
		}

		int minIncrementForUnique(vector<int>& A) {

			int result = 0;
			sort(A.begin(), A.end());
			for (int i = 1; i < A.size(); ++i)
			{
				if (A[i] <= A[i - 1])
				{					
					result += A[i - 1] - A[i] + 1;
					A[i] = A[i-1] + 1;					
				}
			}

			return result;
		}
	};

	TEST(Interview, minIncrementForUnique)
	{
		Solution s;
		ASSERT_EQ(s.minIncrementForUnique(vector<int>{1, 2, 2}), 1);
		ASSERT_EQ(s.minIncrementForUnique(vector<int>{3, 2, 1, 2, 1, 7}), 6);
	}
}