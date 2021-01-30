#include <gtest/gtest.h>
using namespace std;

namespace IV22_2
{
	/*
	����������һЩ��������ɵ��б�ÿ�������б��ǳɶԲ��ཻ�ģ������Ѿ�����
	���������������б�Ľ�����
	����ʽ�ϣ������� [a, b]������ a <= b����ʾʵ�� x �ļ��ϣ��� a <= x <= b������������Ľ�����һ��ʵ����ҪôΪ�ռ���ҪôΪ�����䡣���磬[1, 3] �� [2, 4] �Ľ���Ϊ [2, 3]����
 
	ʾ����

	���룺A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
	�����[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
	ע�⣺��������������������������ɵ��б�������������б�
 
	��ʾ��
	0 <= A.length < 1000
	0 <= B.length < 1000
	0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
	*/

	class Solution {
	public:
		vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {

			vector<vector<int>> result;
			int posA = 0;
			int posB = 0;
			
			while (posA < A.size() && posB < B.size())
			{
				if (A[posA][0] <= B[posB][1] && A[posA][1] >= B[posB][0])
				{					
					result.push_back(vector<int>{ 
						max(A[posA][0],B[posB][0]),
						min(A[posA][1], B[posB][1]),
					});

					if (A[posA][1] > B[posB][1])
					{
						posB++;
					}
					else
					{
						posA++;
					}
				}
				else if (A[posA][0] > B[posB][1])
				{
					posB++;
				}
				else
				{
					posA++;
				}
			}

			return result;
		}
	};

	TEST(Interview, intervalIntersection)
	{
		Solution s;
		vector<vector<int>> A{ {0,2},{5,10},{13,23},{24,25} };
		vector<vector<int>> B{ {1,5},{8,12},{15,24},{25,26} };
		s.intervalIntersection(A,B);
	}
}