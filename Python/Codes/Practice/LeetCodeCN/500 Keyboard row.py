
class Solution:

    #键盘布局
    keyboard = [{'Q','W','E','R','T','Y','U','I','O','P'},
                {'A','S','D','F','G','H','J','K','L'},
                {'Z','X','C','V','B','N','M'}]

    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """        
        for v in words:
            index = -1

            for i in v:
                


