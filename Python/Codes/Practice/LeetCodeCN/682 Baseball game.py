class Solution:
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        result = []
        for v in ops:
            length = len(result)
            if v == '+':
                if length >= 2:
                    result.append(result[length-1] + result[length-2])
            elif v == 'D':
                if length >= 1:
                    result.append(result[length-1]*2)
            elif v == 'C':
                if length >= 1:
                    result.pop()
            else:
                result.append(int(v))

        return sum(result)

if __name__ == '__main__':
    s = Solution()
    print(s.calPoints(["5","2","C","D","+"]))
    print(s.calPoints(["5","-2","4","C","D","9","+","+"]))
    print(s.calPoints(["D","-2","C","C","D","9","+","C"]))