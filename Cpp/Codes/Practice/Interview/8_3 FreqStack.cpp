#include <gtest/gtest.h>
#include <unordered_map>
#include <queue>
using namespace std;


/*
实现 FreqStack，模拟类似栈的数据结构的操作的一个类。
FreqStack 有两个函数：
push(int x)，将整数 x 推入栈中。
pop()，它移除并返回栈中出现最频繁的元素。
如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。

示例：
输入：
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
输出：[null,null,null,null,null,null,null,5,7,5,4]
解释：
执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：

pop() -> 返回 5，因为 5 是出现频率最高的。
栈变成 [5,7,5,7,4]。

pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
栈变成 [5,7,5,4]。

pop() -> 返回 5 。
栈变成 [5,7,4]。

pop() -> 返回 4 。
栈变成 [5,7]。
*/

namespace IV8_3
{
	class FreqStack {
	public:
		FreqStack() {}

		void push(int x) {
			int key = (++freq[x] << 16) | (++seq);
			queue.emplace(key, x);
		}

		int pop() {
			int x = queue.top().second; 
			queue.pop();
			if (--freq[x] == 0)
				freq.erase(x);
			return x;
		}
	private:
		int seq = 0;
		unordered_map<int, int> freq;
		priority_queue<pair<int, int>> queue;
	};

	TEST(Interview, FreqStack)
	{
		FreqStack s;
		s.push(5);
		s.push(7);
		s.push(5);
		s.push(7);
		s.push(4);
		s.push(5);

		auto result = s.pop();
		result = s.pop();
		result = s.pop();
		result = s.pop();
	}
}