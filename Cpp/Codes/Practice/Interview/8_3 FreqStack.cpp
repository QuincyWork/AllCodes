#include <gtest/gtest.h>
#include <unordered_map>
#include <queue>
using namespace std;


/*
ʵ�� FreqStack��ģ������ջ�����ݽṹ�Ĳ�����һ���ࡣ
FreqStack ������������
push(int x)�������� x ����ջ�С�
pop()�����Ƴ�������ջ�г�����Ƶ����Ԫ�ء�
�����Ƶ����Ԫ�ز�ֻһ�������Ƴ���������ӽ�ջ����Ԫ�ء�

ʾ����
���룺
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
�����[null,null,null,null,null,null,null,5,7,5,4]
���ͣ�
ִ������ .push ������ջ�Ե�����Ϊ [5,7,5,7,4,5]��Ȼ��

pop() -> ���� 5����Ϊ 5 �ǳ���Ƶ����ߵġ�
ջ��� [5,7,5,7,4]��

pop() -> ���� 7����Ϊ 5 �� 7 ����Ƶ����ߵģ��� 7 ��ӽ�ջ����
ջ��� [5,7,5,4]��

pop() -> ���� 5 ��
ջ��� [5,7,4]��

pop() -> ���� 4 ��
ջ��� [5,7]��
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