#include <gtest/gtest.h>
using namespace std;

namespace LC86
{
	/**
	 * Definition for singly-linked list. */
	 struct ListNode {
	     int val;
	     ListNode *next;
	     ListNode(int x) : val(x), next(NULL) {}
	 };
	 
	class Solution {
	public:
		ListNode* partition(ListNode* head, int x) {

			ListNode* left = nullptr;
			ListNode* leftRoot = nullptr;
			ListNode* right = nullptr;
			ListNode* rightRoot = nullptr;

			while (head)
			{
				if (head->val < x)
				{
					if (left)
					{
						left->next = head;
						left = head;
					}
					else
					{
						leftRoot = left = head;
					}
				}
				else
				{
					if (right)
					{
						right->next = head;
						right = head;
					}
					else
					{
						rightRoot = right = head;
					}
				}
				
				auto swap = head->next;
				head->next = nullptr;
				head = swap;
			}

			if (left)
			{
				left->next = rightRoot;
			}
			else
			{
				leftRoot = rightRoot;
			}

			return leftRoot;
		}
	};

	TEST(LeetCodeCN, tPartition)
	{
		Solution s;
		ListNode v1[] = { 1,4,3,2,5,2 };
		for (int i = 0; i < _countof(v1) - 1; ++i)
		{
			v1[i].next = &v1[i + 1];
		}

		auto result = s.partition(v1,3);

	}
}