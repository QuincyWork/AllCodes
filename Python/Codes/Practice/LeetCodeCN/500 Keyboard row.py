
class Solution:

    #键盘布局
    keyboard = {'Q':1,'W':1,'E':1,'R':1,'T':1,'Y':1,'U':1,'I':1,'O':1,'P':1,
                'A':2,'S':2,'D':2,'F':2,'G':2,'H':2,'J':2,'K':2,'L':2,
                'Z':3,'X':3,'C':3,'V':3,'B':3,'N':3,'M':3}

    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """       
        result = []
        for v in words:

            value = v.upper()
            index = 0
            
            for i in value:
                t = self.keyboard[i]
                if index == 0:
                    index = t
                elif index != t:
                    index = -1
                    break;

            if index != -1:
                result.append(v)


        return result

    def findWords1(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """ 
        keybrds = ['QWERTYUIOP','ASDFGHJKL','ZXCVBNM']
        result  = []
        
        for v in words:
            value = v.upper()
            if (all([x in keybrds[0] for x in value]) or 
                all([x in keybrds[1] for x in value]) or 
                all([x in keybrds[2] for x in value])):
                result.append(v)

        return result


if __name__ == '__main__':
    s = Solution()
    print(s.findWords1(["Hello", "Alaska", "Dad", "Peace"]))


                


