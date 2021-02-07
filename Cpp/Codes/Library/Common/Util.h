#pragma once
#include <string>
// ¸¨Öúº¯Êı

template <typename C, typename T>
static std::size_t strsplit(const std::basic_string<T>& str, C& cont,
	T delim)
{
	std::size_t current, previous = 0, count = 0;
	current = str.find(delim);
	while (current != std::string::npos)
	{
		cont.push_back(str.substr(previous, current - previous));
		count++;
		previous = current + 1;
		current = str.find(delim, previous);
	}
	cont.push_back(str.substr(previous, current - previous));
	return count;
}