#include <gtest/gtest.h>
using namespace std;

namespace IV18_2
{
	/*
	给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
	k 是一个正整数，它的值小于或等于链表的长度。
	如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
	示例 :
	给定这个链表：1->2->3->4->5
	当 k = 2 时，应当返回: 2->1->4->3->5
	当 k = 3 时，应当返回: 3->2->1->4->5
	说明 :
	你的算法只能使用常数的额外空间。
	你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
	*/

	struct ListNode {

		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};

	class Solution {
	public:
		ListNode* reverseKGroup(ListNode* head, int k) {

			ListNode* root = nullptr;
			ListNode* left = nullptr;
			ListNode* prev = nullptr;
			ListNode* first = nullptr;
			ListNode* current = head;

			while (current != nullptr)
			{
				first = current;
				for (int i = 0; i < k; ++i)
				{
					if (current == nullptr)
					{
						break;
					}
					
					ListNode* temp = current->next;
					current->next = prev;
					prev = current;
					current = temp;
				}

				if (root == nullptr)
				{
					root = current;
				}

				left = first;

				first->next = current->next;
				current = first->next;
			}

			return root;
		}
	};

	TEST(Interview, reverseKGroup)
	{
		Solution s;
		ListNode d[] = {1,2,3,4,5};
		for (int i = 1; i < _countof(d); ++i)
		{
			d[i - 1].next = &d[i];
		}

		s.reverseKGroup(d, 2);
		
	}
}