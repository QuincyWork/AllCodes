
class Solution:
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        lines = 1
        current = 0

        for x in S:
            width = widths[ord(x) - ord('a')] 
            if current + width  > 100:
                lines += 1
                current = width
            else:
                current += width
       
        return [lines,current]

if __name__ == '__main__':
    s = Solution()
    print(s.numberOfLines([10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10],"abcdefghijklmnopqrstuvwxyz"))
    print(s.numberOfLines([4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10],"bbbcccdddaaa"))