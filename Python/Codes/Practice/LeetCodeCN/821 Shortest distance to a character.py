
class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        pos = []
        for i,v in enumerate(S):
            if v == C:
                pos.append(i)

        result = []
        begin = -20000
        next = pos.pop(0)
        for i in range(len(S)):
            if i > next:
                begin = next
                next = len(pos) and pos.pop(0) or 20000                

            result.append(min(i - begin, next-i))

        return result


if __name__ == '__main__':
    s = Solution()
    print(s.shortestToChar('gtywtbcnowpwibfdgvph','i'))
    print(s.shortestToChar('loveleetcode','e'))