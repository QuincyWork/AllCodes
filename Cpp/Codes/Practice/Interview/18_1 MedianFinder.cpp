#include <gtest/gtest.h>
using namespace std;

namespace IV18_1
{
	/*
	中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
	例如，
	[2,3,4] 的中位数是 3
	[2,3] 的中位数是 (2 + 3) / 2 = 2.5
	设计一个支持以下两种操作的数据结构：
	void addNum(int num) - 从数据流中添加一个整数到数据结构中。
	double findMedian() - 返回目前所有元素的中位数。
	示例：
	addNum(1)
	addNum(2)
	findMedian() -> 1.5
	addNum(3) 
	findMedian() -> 2
	进阶:
	如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
	如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
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