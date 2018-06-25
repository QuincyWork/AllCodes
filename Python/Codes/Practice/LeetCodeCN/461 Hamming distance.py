
class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        count = 0
        v = x ^ y
        while v:
            count += v % 2
            v >>= 1

        return count


if __name__ == '__main__':
    s = Solution()
    print(s.hammingDistance(1,4))
    print(s.hammingDistance(56,281238))
