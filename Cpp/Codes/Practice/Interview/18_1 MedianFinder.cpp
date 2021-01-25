#include <gtest/gtest.h>
using namespace std;

namespace IV18_1
{
	/*
	��λ���������б��м����������б�����ż������λ�������м���������ƽ��ֵ��
	���磬
	[2,3,4] ����λ���� 3
	[2,3] ����λ���� (2 + 3) / 2 = 2.5
	���һ��֧���������ֲ��������ݽṹ��
	void addNum(int num) - �������������һ�����������ݽṹ�С�
	double findMedian() - ����Ŀǰ����Ԫ�ص���λ����
	ʾ����
	addNum(1)
	addNum(2)
	findMedian() -> 1.5
	addNum(3) 
	findMedian() -> 2
	����:
	����������������������� 0 �� 100 ��Χ�ڣ��㽫����Ż�����㷨��
	����������� 99% ���������� 0 �� 100 ��Χ�ڣ��㽫����Ż�����㷨��
	*/

	class MedianFinder {
	public:
		/** initialize your data structure here. */
		MedianFinder() {

		}

		void addNum(int num) {

			bool insert = false;
			for (auto it = data.begin(); it != data.end(); ++it)
			{
				if (*it > num)
				{
					data.insert(it, num);
					insert = true;
					break;
				}
			}

			if (!insert)
			{
				data.push_back(num);
			}
		}

		double findMedian() {

			int length = data.size();
			if (length == 0)
			{
				return 0;
			}

			if (length % 2 == 0)
			{
				return (data[(length - 1) / 2] + data[(length + 1) / 2]) / 2.0;
			}
			else
			{
				return data[length / 2];
			}
		}

	private:
		vector<int> data;
	};

	/**
	 * Your MedianFinder object will be instantiated and called as such:
	 * MedianFinder* obj = new MedianFinder();
	 * obj->addNum(num);
	 * double param_2 = obj->findMedian();
	 */

	TEST(Interview, MedianFinder)
	{
		MedianFinder s;
		s.addNum(2);
		s.addNum(3);
		s.addNum(4);
		s.addNum(1);
		ASSERT_EQ(s.findMedian(), 3);
	}
}