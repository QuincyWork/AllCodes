
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def trimBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: TreeNode
        """
        if not root:
            return root

        if  L <= root.val <= R:
            root.left = self.trimBST(root.left,L,R)
            root.right = self.trimBST(root.right,L,R)
        elif root.val < L:
            root = self.trimBST(root.right,L,R)
        elif root.val > R:
            root = self.trimBST(root.left,L,R)

        return root


if __name__ == '__main__':
    s = Solution()    
