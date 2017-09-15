
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    __SERIALIZE_TAG = '#'

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """

        value = ""
        nodes = [root]
        while nodes:
            currentNode = nodes.pop(0)
            if currentNode:
                value += str(currentNode.val) + self.__SERIALIZE_TAG
                nodes.append(currentNode.left)
                nodes.append(currentNode.right)                
            else:
                value += self.__SERIALIZE_TAG
                      
        return value


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        values = data.split(self.__SERIALIZE_TAG)
        if not values or not values[0]:
            return None

        treeRoot = TreeNode(int(values.pop(0)))
        nodes = [treeRoot]
        while values and nodes:
            currentNode = nodes.pop(0)
            value = values.pop(0)
            if value:
                currentNode.left = TreeNode(int(value))
                nodes.append(currentNode.left)

            value = values.pop(0)
            if value:
                currentNode.right = TreeNode(int(value))
                nodes.append(currentNode.right)
        
        return treeRoot


if __name__ == '__main__':
    nodes = [TreeNode(0),TreeNode(1),TreeNode(2),TreeNode(3),TreeNode(4),TreeNode(5)]
    nodes[0].left = nodes[1]
    nodes[0].right = nodes[2]
    nodes[1].left = nodes[3]    
    nodes[2].left = nodes[4]
    nodes[3].right = nodes[5]

    value = Codec().serialize(nodes[0])
    print(value)

    tree = Codec().deserialize(value)
    print(tree)