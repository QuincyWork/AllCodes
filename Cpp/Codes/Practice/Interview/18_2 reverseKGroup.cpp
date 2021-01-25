#include <gtest/gtest.h>
using namespace std;

namespace IV18_2
{
	/*
	����һ������ÿ k ���ڵ�һ����з�ת�����㷵�ط�ת�������
	k ��һ��������������ֵС�ڻ��������ĳ��ȡ�
	����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��
	ʾ�� :
	�����������1->2->3->4->5
	�� k = 2 ʱ��Ӧ������: 2->1->4->3->5
	�� k = 3 ʱ��Ӧ������: 3->2->1->4->5
	˵�� :
	����㷨ֻ��ʹ�ó����Ķ���ռ䡣
	�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����
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