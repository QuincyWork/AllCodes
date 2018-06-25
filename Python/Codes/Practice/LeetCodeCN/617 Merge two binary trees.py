
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        
        if not t1 or not t2:
            return t1 or t2

        t1.val += t2.val
        t1.left = self.mergeTrees(t1.left,t2.left)
        t1.right = self.mergeTrees(t1.right,t2.right)
        return t1

    
if __name__ == '__main__':
    s = Solution()
    t1 = [TreeNode(1),TreeNode(3),TreeNode(2),TreeNode(5)]
    t1[0].left = t1[1]
    t1[0].right = t1[2]
    t1[1].left = t1[3]    

    t2 = [TreeNode(2),TreeNode(1),TreeNode(3),TreeNode(4),TreeNode(7)]
    t2[0].left = t2[1]
    t2[0].right = t2[2]
    t2[1].right = t2[3]
    t2[2].right = t2[4]

    result = s.mergeTrees(t1[0],t2[0])