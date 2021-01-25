#include <gtest/gtest.h>
#include <stack>
using namespace std;

/*
�����ļҾӳǴ������������һֱ���ǵĿɵ�����ܣ�������Լ����鶼�����µ�����ϡ�
���Ҫ�ڷŵ��� books ������ã�����һ�����������£��� i ����ĺ��Ϊ books[i][0]���߶�Ϊ books[i][1]��
��˳�� ����Щ��ڷŵ��ܿ��Ϊ shelf_width ������ϡ�
��ѡ�������������ϣ����ǵĺ��֮��С�ڵ�����ܵĿ�� shelf_width����Ȼ���ٽ�һ����ܡ��ظ�������̣�ֱ�������е��鶼��������ϡ�
��Ҫע����ǣ����������̵�ÿ�������У��ڷ����˳����������õ�˳����ͬ�� ���磬��������� 5 ���飬��ô���ܵ�һ�ְڷ�����ǣ���һ�͵ڶ�������ڵ�һ������ϣ�����������ڵڶ�������ϣ����ĺ͵��屾��������һ������ϡ�
ÿһ�����ڷŵ�������߶Ⱦ�����һ����ܵĲ�ߣ��������ĸ߶�Ϊ�����֮�͡�
�����ַ�ʽ������ܣ��������������ܵ���С�߶ȡ�

ʾ����

���룺books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
�����6
���ͣ�
3 ����ܵĸ߶Ⱥ�Ϊ 1 + 3 + 2 = 6 ��
�� 2 ���鲻�ط��ڵ�һ������ϡ�

��ʾ��
1 <= books.length <= 1000
1 <= books[i][0] <= shelf_width <= 1000
1 <= books[i][1] <= 1000
*/
namespace IV12_2
{
	class Solution {
	public:
		int minHeightShelves(vector<vector<int>>& books, int shelf_width) {

			vector<int> sheights;
			vector<int> sbooks;

			for (auto& v : books)
			{
				int w = v[0];
				int h = v[1];				
				int pos = sbooks.size() - 1;
				int minH = h;
				while (pos >= 0)
				{
					minH = h + sheights[pos];
					int lw = sbooks[pos] & 0xFF;
					int lh = sbooks[pos] >> 16;
					if (lw + w <= shelf_width )
					{
						if (pos == 0)
						{
							minH = max(h, lh);
							--pos;
						}
						else if ((sbooks[pos - 1] & 0xFF) + lw + w <= shelf_width)
						{
							w += lw;
							h = max(h, lh);
							--pos;
							continue;
						}
						else if(minH >= sheights[pos - 1] + max(h, lh))
						{
							w += lw;
							h = max(h, lh);
							--pos;
							continue;
						}
					}

					break;
				}

				sbooks.push_back(v[1] << 16 | v[0]);
				sheights.push_back(minH);
			}

			return sheights.back();
		}
	};

	TEST(Interview, minHeightShelves)
	{
		Solution s;
		vector<vector<int>> d;
		d.push_back(vector<int>{1, 1});
		d.push_back(vector<int>{2, 3});
		d.push_back(vector<int>{2, 3});
		d.push_back(vector<int>{1, 1});
		d.push_back(vector<int>{1, 1});
		d.push_back(vector<int>{1, 1});
		d.push_back(vector<int>{1, 2});

		ASSERT_EQ(s.minHeightShelves(d,4),6);

		vector<vector<int>> d1;
		d1.push_back(vector<int>{1, 3});
		d1.push_back(vector<int>{2, 4});
		d1.push_back(vector<int>{3, 2});
		ASSERT_EQ(s.minHeightShelves(d1, 6), 4);
	}
}
