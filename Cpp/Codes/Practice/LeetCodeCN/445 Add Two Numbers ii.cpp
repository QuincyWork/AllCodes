#include <gtest/gtest.h>
#include <stack>
using namespace std;

namespace LC445
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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

			stack<ListNode*> v1;
			while (l1)
			{
				v1.push(l1);
				l1 = l1->next;
			}

			stack<ListNode*> v2;
			while (l2)
			{
				v2.push(l2);
				l2 = l2->next;
			}
			
			ListNode* root = nullptr;
			int carry = 0;

			while (!v1.empty() || !v2.empty())
			{
				int sum = 0;
				if (!v1.empty())
				{
					l1 = v1.top();
					v1.pop();
					sum += l1->val;
				}

				if (!v2.empty())
				{
					l2 = v2.top();
					v2.pop();
					sum += l2->val;
				}

				auto node = new ListNode((sum + carry) % 10);
				carry = (sum + carry) / 10;
				node->next = root;
				root = node;
			}

			if (carry > 0)
			{
				auto node = new ListNode(carry);				
				node->next = root;
				root = node;
			}

			return root;
		}
	};

	TEST(LeetCodeCN, tAddTwoNumbers)
	{
		Solution s;
		ListNode v1[] = { 7,2,4,3 };
		for (int i = 0; i < 3; ++i)
		{
			v1[i].next = &v1[i + 1];
		}

		ListNode v2[] = { 5,6,4 };
		for (int i = 0; i < 2; ++i)
		{
			v2[i].next = &v2[i + 1];
		}
		
		ListNode* result = s.addTwoNumbers(v1,v2);		
		
	}
}