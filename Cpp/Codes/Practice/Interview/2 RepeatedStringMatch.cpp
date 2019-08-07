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
				// A包含B，则直接返回
				count = 1;
			}
			else
			{
				// A不包含B，则A的后缀数组包含B的前缀数组
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
					// 判断中间一段相同
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

					// 判断最后一段，A的前缀等于B
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