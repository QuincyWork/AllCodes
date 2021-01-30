#pragma once
#include <vector>

namespace TestData
{	
	/// 已有测试数据
	template<int>
	std::vector<std::vector<int>> AllData()
	{
		std::vector<std::vector<int>> v;
		v.push_back(std::vector<int>() { 1 });
		v.push_back(std::vector<int>() { 1, 0, 1, 2 });
		v.push_back(std::vector<int>() { 1, 4, 3, 5, 2 });		
		v.push_back(std::vector<int>() { 3, 4, 2, 3, 6, 1, 6, 7, 4, 3, 10, 13, 3, 15 });
		v.push_back(std::vector<int>() { 4, 5, 2, 34, 6, 2, 3, 8, 7, 1, 2, 3, 6, 7, 9, 3, 4, 6, 2 });
		v.push_back(std::vector<int>() { 4, 3, 1, 23, 5, 6, 2, 2, 3, 44, 1, 9, 7, 0, 123, 3, 34, 1, 36, 7, 10 });
		
		return v;
	}

	/// 根据输入数据产生
	template<class T>
	std::vector<T> Data(size_t count, T p1, ...)
	{
		std::vector<T> v;
		va_list st;
		va_start(st, p1);
		v.push_back(p1);

		while (count-- > 1)
		{
			v.push_back(va_arg(st, T));
		}

		va_end(st);
		return v;
	}

	/// 根据输入数组产生
	template<class T>
	std::vector<T> Data(size_t count, T p[])
	{
		std::vector<T> v;
		v.assign(p, p + count);
	}

	/// 产生指定长度的随机数组
	template<class T>
	std::vector<T> Data(size_t count, T min, T max)
	{
		std::vector<T> v;
		auto delta = max - min;
		while (count-- > 0)
		{
			v.push_back(min + rand() * delta);
		}

		return count;
	}
}
