#include <gtest\gtest.h>
#include <queue>
using namespace std;

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) 
{
	vector<pair<int, int>> state;
	for (size_t i = 0; i < quality.size(); ++i)
	{
		state.push_back(make_pair((double)wage[i] / quality[i], quality[i]));
	}

	sort(state.begin(), state.end(), [](auto a, auto b) -> bool { return a.first < b.first; });

	priority_queue<int> queue;
	double sum = 0;
	for (size_t i = 0; i < K; ++i)
	{
		queue.push(state[i].second);
		sum += state[i].second;
	}

	double result = sum * state[K - 1].first;
	for (size_t i = K; i < state.size(); ++i)
	{

	}

	return 0;
}