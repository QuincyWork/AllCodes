
class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        result = "0b"
        value = bin(num)
        for i in range(2,len(value)):
            result += value[i]=='1' and '0' or '1'
        
        return int(result,2)

    def findComplement1(self, num):
        """
        :type num: int
        :rtype: int
        """
        return num ^ int('1' * len(bin(num)[2:]),2)

    def findComplement2(self, num):
        """
        :type num: int
        :rtype: int
        """
        i = 1
        while i <= num:
            num ^= i
            i <<= 1

        return num


if __name__ == '__main__':
    s = Solution()
    print(s.findComplement2(5))
    print(s.findComplement2(1))
