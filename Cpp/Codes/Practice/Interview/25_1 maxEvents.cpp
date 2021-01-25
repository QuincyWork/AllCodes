#include <gtest/gtest.h>
#include <unordered_set>
using namespace std;

namespace IV25_1
{
	/*
	����һ������ events������ events[i] = [startDayi, endDayi] ����ʾ���� i ��ʼ�� startDayi �������� endDayi ��
����������� startDayi <= d <= endDayi �е�����һ�� d �μӻ��� i ��ע�⣬һ��ֻ�ܲμ�һ�����顣
���㷵������Բμӵ� ��� ������Ŀ��

ʾ�� 1��

���룺events = [[1,2],[2,3],[3,4]]
�����3
���ͣ�����Բμ����е��������顣
���Ż����һ�ַ�������ͼ��
�� 1 ��μӵ�һ�����顣
�� 2 ��μӵڶ������顣
�� 3 ��μӵ��������顣
ʾ�� 2��
���룺events= [[1,2],[2,3],[3,4],[1,2]]
�����4
ʾ�� 3��
���룺events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
�����4
ʾ�� 4��
���룺events = [[1,100000]]
�����1
ʾ�� 5��
���룺events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
�����7

��ʾ��
1 <= events.length <= 10^5
events[i].length == 2
1 <= events[i][0] <= events[i][1] <= 10^5
	*/

	class Solution {
	public:

		int maxEvents(vector<vector<int>>& events) {

			sort(events.begin(), events.end(), [](const vector<int>& e1, const vector<int>& e2) {
				return e1[1] < e2[1];
				});

			unordered_set<int> res;
			for (vector<int> e : events) {
				for (int d = e[0]; d <= e[1]; d++) {
					if (res.find(d) == res.end()) {
						res.insert(d);
						break;
					}
				}
			}

			return res.size();
		}
	};

	TEST(Interview, maxEvents)
	{
		Solution s;

		ASSERT_EQ(s.maxEvents(vector<vector<int>>{ {1, 2}, { 2,3 }, { 3,4 } }), 3);
		ASSERT_EQ(s.maxEvents(vector<vector<int>>{ {1, 2}, { 2,3 }, { 3,4 }, { 1,2 } }), 4);
		ASSERT_EQ(s.maxEvents(vector<vector<int>>{ {1, 4}, { 4,4 }, { 2,2 }, { 3,4 }, { 1,1 } }), 4);

	}
}