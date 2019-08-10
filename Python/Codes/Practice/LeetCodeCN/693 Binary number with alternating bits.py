
class Solution:
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        value = bin(n)[2:]
        for i in range(0,len(value)-1):
            if abs(int(value[i]) - int(value[i+1])) != 1:
                return False

        return True

    def hasAlternatingBits1(self, n):
        """
        :type n: int
        :rtype: bool
        """
        value = bin(n)[2:]
        odd = value[::2]
        even = value[1::2]

        if ('1' in odd and '1' in even) or ('0' in odd  and '0' in even):
            return False

        return True


if __name__ == '__main__':
    s = Solution()
    print(s.hasAlternatingBits(5))
    print(s.hasAlternatingBits(7))
    print(s.hasAlternatingBits(11))