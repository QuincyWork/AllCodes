"""
给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

"""

# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return None
        self.connectSub(root.left,root.right)
        return root

    def connectSub(self,left,right):
        if not left or not right:
            return
        left.next = right
        self.connectSub(left.left,left.right)
        self.connectSub(right.left,right.right)
        self.connectSub(left.right,right.left)


if __name__=="__main__":
    s = Solution()
    data = []
    for i in range(1,8):
        data.append(Node(i))

    data[0].left = data[1]
    data[0].right = data[2]
    data[1].left = data[3]
    data[1].right = data[4]
    data[2].left = data[5]
    data[2].right = data[6]
    s.connect(data[0])

