#pragma once
#include <vector>
#include <string>
#include <stdarg.h>

// ≥ı ºªØ
class Vector
{
public:

	template<typename T>
	std::vector<T> operator() (int s,T p1, ...) const
	{
		std::vector<T> v;		
		va_list st;
		va_start(st,p1);
		v.push_back(p1);

		while (s-- > 1)
		{	
			v.push_back(va_arg(st, T));
		}
		
		va_end(st);

		return v;
	}
};

#define V Vector()

// VS2017 does not contain greater<T>,define
template <class T> struct greater {
	bool operator() (const T& x, const T& y) const { return x>y; }
	typedef T first_argument_type;
	typedef T second_argument_type;
	typedef bool result_type;
};