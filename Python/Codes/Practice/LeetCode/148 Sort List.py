
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head.next:
            return head

        if head.val < head.next.val:
            left  = head
            right = head.next
        else:
            left  = head.next
            right = head
        pivot = left.val
        leftNext = left
        rightNext = right

        current = head.next.next
        while current:
            if current.val > pivot:
                rightNext.next = current
                rightNext = current
            else:
                leftNext.next = current
                leftNext = current

        left = sortList(self,left)
        right = sortList(self,right)

        current = left
        while current.next:
            current = current.next
        
        current.next = right

        return left

if __name__ == '__main__':
    nodes = [ListNode(0),ListNode(1),ListNode(2),ListNode(3),ListNode(4),ListNode(5)]