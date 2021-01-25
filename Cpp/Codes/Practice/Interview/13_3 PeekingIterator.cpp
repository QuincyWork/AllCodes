#include <gtest/gtest.h>
using namespace std;

/*
����һ����������Ľӿڣ��ӿڰ������������� next() �� hasNext()����Ʋ�ʵ��һ��֧�� peek() �����Ķ��˵����� -- �䱾�ʾ��ǰ�ԭ��Ӧ�� next() �������ص�Ԫ�� peek() ������
ʾ��:
�������������ʼ��Ϊ�б� [1,2,3]��

���� next() ���� 1���õ��б��еĵ�һ��Ԫ�ء�
���ڵ��� peek() ���� 2����һ��Ԫ�ء��ڴ�֮����� next() ��Ȼ���� 2��
���һ�ε��� next() ���� 3��ĩβԪ�ء��ڴ�֮����� hasNext() Ӧ�÷��� false��
���ף��㽫�����չ�����ƣ�ʹ֮���ͨ�û����Ӷ���Ӧ���е����ͣ�����ֻ�������ͣ�
*/

namespace IV13_3
{
	// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

	class Iterator {
		
	protected:
		struct Data {
			int* buf;
			int idx;
			int size;
		};
		Data* data;


	public:
		Iterator(const vector<int>& nums)
		{
			data = new Data();
			data->buf = (int*)nums.data();			
			data->idx = 0;
			data->size = nums.size();
		}

		Iterator(const Iterator& iter)
		{
			data = new Data();
			data->buf = iter.data->buf;
			data->idx = iter.data->idx;
			data->size = iter.data->size;
		}

		virtual ~Iterator()
		{
			delete data;
			data = NULL;
		}

		// Returns the next element in the iteration.
		int next()
		{
			if (data == NULL || data->idx>= data->size)
			{
				throw "invalid";
			}

			return data->buf[data->idx++];
		}

		// Returns true if the iteration has more elements.
		bool hasNext() const
		{
			return (data->idx < data->size);
		}
	};

	class PeekingIterator : public Iterator {
	public:
		PeekingIterator(const vector<int>& nums) : Iterator(nums) {
			// Initialize any member here.
			// **DO NOT** save a copy of nums and manipulate it directly.
			// You should only use the Iterator interface methods.			
		}

		// Returns the next element in the iteration without advancing the iterator.
		int peek() {

			if (data == NULL || data->idx >= data->size)
			{
				throw "invalid";
			}
			
			return data->buf[data->idx];
		}

		// hasNext() and next() should behave the same as in the Iterator interface.
		// Override them if needed.
		int next() {

			return Iterator::next();
		}

		bool hasNext() const {

			return Iterator::hasNext();
		}

	};

	TEST(Interview, tPeekingIterator)
	{
		vector<int> v{1, 2, 3};
		PeekingIterator it(v);
		ASSERT_EQ(it.next(), 1);
		ASSERT_EQ(it.peek(), 2);
		ASSERT_EQ(it.next(), 2);
		ASSERT_EQ(it.next(), 3);
		ASSERT_EQ(it.hasNext(), false);
	}
}