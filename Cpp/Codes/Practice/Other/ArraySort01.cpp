#include <gtest/gtest.h>
#include <Data/ArrayData.h>
using namespace std;

// 
namespace ARRAY_SORT01 {
	
	// 默认安装升序排列
	template<class T> 
	class Sort
	{
	public:
		// 冒泡
		// 不断交换相邻的元素，是的未排序中最小元素不断向前移动
		static void Bubble(T A[], size_t size)
		{
			for (size_t i = 0; i < size; ++i)
			{
				for (size_t j = size - 1; j > i; --j)
				{
					if (A[j - 1] > A[j])
					{
						T t = A[j - 1];
						A[j - 1] = A[j];
						A[j] = t;
					}
				}
			}
		}
		
		// 选择
		// 从未排序的数组中找出最小的，放到已排序后面
		static void Select(T A[], size_t size)
		{
			for (size_t i = 0; i < size; ++i)
			{
				for (size_t j = i + 1; j < size; ++j)
				{
					if (A[i] > A[j])
					{
						T t = A[i];
						A[i] = A[j];
						A[j] = t;
					}
				}
			}
		}
		
		// 插入
		// 把未排序元素插入到已排序中
		static void Insert(T A[], size_t size)
		{
			for (size_t i = 1; i < size; ++i)
			{
				if (A[i - 1] > A[i])
				{
					T t = A[i];
					int j = i;
					while (j > 0 && A[j - 1] > t)
					{
						A[j] = A[j - 1];
						j--;
					}

					A[j] = t;
				}
			}
		}

		// 合并
		// 把未排序数组分成两个子数组，再进行合并
		static void Merge(T A[], size_t left, size_t right)
		{
			if (left < right)
			{
				size_t mid = left + (right - left) / 2;
				Merge(A, left, mid);
				Merge(A, mid + 1, right);

				// 合并,新建一个数组，只有A数组left-right范围数据，索引需要处理
				T* B = new T[right - left + 1];
				memcpy(B, A + left, (right - left + 1) * sizeof(T));
				size_t i = 0;
				size_t j = mid + 1 - left;
				size_t p = left;
				while (i <= (mid - left) && j <= (right - left))
				{
					if (B[i] < B[j])
					{
						A[p++] = B[i++];
					}
					else
					{
						A[p++] = B[j++];
					}
				}

				while (i <= (mid - left))
				{
					A[p++] = B[i++];
				}
			}
		}

		// 快速排序
		// 选择中枢值，中枢值把序列分成两个子序列。使得左子序列的值都小于等于中枢值，右子序列的值都大于等于中枢值。
		// 然后每个子序列按照同样的方法再递归的排序
		static int Partition(T A[], int left, int right)
		{
			int p = left;
			for (int i = left; i < right; ++i)
			{
				if (A[i] <= A[right])
				{
					T temp = A[p];
					A[p] = A[i];
					A[i] = temp;
					++p;
				}
			}

			T temp = A[p];
			A[p] = A[right];
			A[right] = temp;

			return p;
		}

		static void Quick(T A[], int left, int right)
		{
			if (left < right)
			{
				int p = Partition(A,left,right);
				Quick(A, left, p - 1);
				Quick(A, p + 1, right);
			}
		}

		// Shell排序
		// Shell排序是插入排序的扩展，把大的数组逻辑分组，进成插入排序
		static void Shell(T A[], int size)
		{
			int gap = size / 2;
			while (gap >= 1)
			{
				// 插入算法部分
				for (int i = gap; i < size; ++i)
				{
					int j = i - gap;
					T value = A[i];
					while (j >= 0 && A[j] > value)
					{
						A[j + gap] = A[j];
						j -= gap;
					}

					A[j + gap] = value;
				}

				gap /= 2;
			}
		}

		// 


	};

	TEST(ArraySort01, Sort)
	{
		int d1[] = { 1,4,3,5,2};
		int d2[] = { 3,4,2,3,6,1,6,7,4,3,10,13,3,15 };
		int d3[] = { 4,5,2,34,6,2,3,8,7,1,2,3,6,7,9,3,4,6,2 };
		int d4[] = { 4,5,2,34,6,2,3,8,7,1,2,3,6,7,9,3,4,6,2 };
		int d5[] = { 4,3,1,23,5,6,2,2,3,44,1,9,7,0,123,3,34,1,36,7,10 };
		int d6[] = { 1 };
		int d7[] = { 1,1,1,1 };
		int d8[] = { 0,0,0,0,0,0,0,0 };
		
		/*Sort<int>::Bubble(d1, _countof(d1));
		Sort<int>::Bubble(d2, _countof(d2));
		Sort<int>::Bubble(d3, _countof(d3));
		Sort<int>::Bubble(d4, _countof(d4));
		Sort<int>::Bubble(d5, _countof(d5));
		Sort<int>::Bubble(d6, _countof(d6));
		Sort<int>::Bubble(d7, _countof(d7));
		Sort<int>::Bubble(d8, _countof(d8));

		Sort<int>::Select(d1, _countof(d1));
		Sort<int>::Select(d2, _countof(d2));
		Sort<int>::Select(d3, _countof(d3));
		Sort<int>::Select(d4, _countof(d4));
		Sort<int>::Select(d5, _countof(d5));
		Sort<int>::Select(d6, _countof(d6));
		Sort<int>::Select(d7, _countof(d7));
		Sort<int>::Select(d8, _countof(d8));

		Sort<int>::Insert(d1, _countof(d1));
		Sort<int>::Insert(d2, _countof(d2));
		Sort<int>::Insert(d3, _countof(d3));
		Sort<int>::Insert(d4, _countof(d4));
		Sort<int>::Insert(d5, _countof(d5));
		Sort<int>::Insert(d6, _countof(d6));
		Sort<int>::Insert(d7, _countof(d7));
		Sort<int>::Insert(d8, _countof(d8));

		Sort<int>::Merge(d1, 0, _countof(d1)-1);
		Sort<int>::Merge(d2, 0, _countof(d2)-1);
		Sort<int>::Merge(d3, 0, _countof(d3)-1);
		Sort<int>::Merge(d4, 0, _countof(d4)-1);
		Sort<int>::Merge(d5, 0, _countof(d5)-1);
		Sort<int>::Merge(d6, 0, _countof(d6)-1);
		Sort<int>::Merge(d7, 0, _countof(d7)-1);
		Sort<int>::Merge(d8, 0, _countof(d8)-1);

		Sort<int>::Quick(d1, 0, _countof(d1) - 1);
		Sort<int>::Quick(d2, 0, _countof(d2) - 1);
		Sort<int>::Quick(d3, 0, _countof(d3) - 1);
		Sort<int>::Quick(d4, 0, _countof(d4) - 1);
		Sort<int>::Quick(d5, 0, _countof(d5) - 1);
		Sort<int>::Quick(d6, 0, _countof(d6) - 1);
		Sort<int>::Quick(d7, 0, _countof(d7) - 1);
		Sort<int>::Quick(d8, 0, _countof(d8) - 1);

		Sort<int>::Shell(d1, _countof(d1) );
		Sort<int>::Shell(d2, _countof(d2) );
		Sort<int>::Shell(d3, _countof(d3) );
		Sort<int>::Shell(d4, _countof(d4) );
		Sort<int>::Shell(d5, _countof(d5) );
		Sort<int>::Shell(d6, _countof(d6) );
		Sort<int>::Shell(d7, _countof(d7) );
		Sort<int>::Shell(d8, _countof(d8) );

		*/
		
		for (auto v : TestData::NDefault())
		{
			Sort<int>::Bubble(v.data(), v.size());
		}

		for (auto v : TestData::NDefault())
		{
			Sort<int>::Select(v.data(), v.size());
		}

		for (auto v : TestData::NDefault())
		{
			Sort<int>::Insert(v.data(), v.size());
		}

		for (auto v : TestData::NDefault())
		{
			Sort<int>::Merge(v.data(), 0, v.size() - 1);
		}

		for (auto v : TestData::NDefault())
		{
			Sort<int>::Quick(v.data(), 0, v.size() - 1);
		}

		for (auto v : TestData::NDefault())
		{
			Sort<int>::Shell(v.data(),v.size());
		}
		
	}
}