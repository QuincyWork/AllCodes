
# define const variable
_MAX_LETTER_SIZE = 27;
_STRING_END_TAG  = '#';

class TireNode(object):
    def __init__(self,x):
        self.value = x
        self.childNodes = {}


class WordDictionary(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TireNode(0)


    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        word = word + _STRING_END_TAG
        currentNode = self.root
        childNode = None

        for value in word:
            childNode = currentNode.childNodes.get(value)
            if not childNode:
                childNode = TireNode(value)
                currentNode.childNodes[value] = childNode
            
            currentNode = childNode
        

    def __searchChild(self,node,value):
        currentNode = node
        if not value:
            return True

        result = False
        if value[0] == '.':
            for key,child in currentNode.childNodes.items():
                if self.__searchChild(child,value[1:]):
                    result = True
                    break
        else:
            child = currentNode.childNodes.get(value[0])
            if child:
                result = self.__searchChild(child,value[1:])

        return result


    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """

        word = word + _STRING_END_TAG
        return self.__searchChild(self.root, word)


if __name__ == '__main__':

    d = WordDictionary()
    d.addWord("bad")
    d.addWord("dad")
    d.addWord("mad")

    print(d.search("bad"))
    print(d.search("pad"))
    print(d.search(".ad"))
    print(d.search("b.."))
