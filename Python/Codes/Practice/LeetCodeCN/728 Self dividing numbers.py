
class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        result = []
        for x in range(left,right+1):
            value = x
            while value :
                t = value % 10
                if not t or x % t:
                    break
                value //= 10
            
            if value == 0:
                result.append(x)

        return result

if __name__ == '__main__':
    s = Solution()
    print(s.selfDividingNumbers(1,22))