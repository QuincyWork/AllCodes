#include <gtest/gtest.h>
using namespace std;

namespace IV2
{
	class Solution {
	public:
		int repeatedStringMatch(string A, string B) {

			int count = -1;
			if (A.find(B) != A.npos)
			{
				// A����B����ֱ�ӷ���
				count = 1;
			}
			else
			{
				// A������B����A�ĺ�׺�������B��ǰ׺����
				int length = min(A.size(), B.size());
				int preSubLength = 0;
				while (length > 0)
				{
					int posA = length - 1;
					int posB = 0;
					while (posA >= 0 && A[posA--] == B[posB++])
						;

					if (posA == -1)
					{
						preSubLength = posB;
						break;
					}

					length--;
				}

				if (preSubLength > 0)
				{
					count++;
					B = B.substr(preSubLength);
					// �ж��м�һ����ͬ
					while (B.size() > A.size())
					{
						if (B.substr(0, A.size()) != A)
						{
							count = -1;
							break;
						}

						B = B.substr(A.size());
						count++;
					}

					// �ж����һ�Σ�A��ǰ׺����B
					if (A.substr(0, B.size()) != B)
					{
						count = -1;
					}
					else
					{
						count++;
					}
				}
			}

			return count;
		}
	};
}