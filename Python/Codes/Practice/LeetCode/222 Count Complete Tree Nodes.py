

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0

        left = self.getHeight(root.left)
        right = self.getHeight(root.right)        
        if left == right:
            return (1<<left) + self.countNodes(root.right)
        else:
            return (1<<right)+ self.countNodes(root.left)            
            
    def getHeight(self,root):
        height = 0
        while root:
            height = height + 1
            root = root.left

        return height


if __name__ == '__main__':

    ## Test Case
    nodes = [TreeNode(0),TreeNode(1),TreeNode(2),TreeNode(3),TreeNode(4),TreeNode(5)]
    nodes[0].left = nodes[1]
    nodes[0].right = nodes[2]
    nodes[1].left = nodes[3]
    nodes[1].right = nodes[4]
    nodes[2].left = nodes[5]
    
    print(Solution().countNodes(nodes[0]));
