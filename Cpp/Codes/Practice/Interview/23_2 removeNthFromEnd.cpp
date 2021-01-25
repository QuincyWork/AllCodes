#include <gtest/gtest.h>
using namespace std;

namespace IV23_2
{
	/*
	����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣
	ʾ����
	����һ������: 1->2->3->4->5, �� n = 2.

	��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
	˵����
	������ n ��֤����Ч�ġ�
	���ף�
	���ܳ���ʹ��һ��ɨ��ʵ����
	*/

 // Definition for singly-linked list.
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
 
	class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {

			ListNode* next = head;
			ListNode* prev = head;
			int pos = 0;
			while (next != nullptr)
			{
				if (pos > n)
				{
					prev = prev->next;
				}

				next = next->next;
			}

			if (prev == head)
			{
				head = prev->next;
			}
			else if (prev->next)
			{
				prev->next = prev->next->next;
			}
			else
			{
				prev->next = nullptr;
			}
		}
	};

	TEST(Interview, removeNthFromEnd)
	{
		
	}

}