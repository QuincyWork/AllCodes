
class Solution:
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        index = 0
        preValue = -1
        for i,v in enumerate(A):
            if v > preValue:
                preValue = v
            elif v < preValue:
                index = i - 1
                break

        return index;

if __name__ == '__main__':
    s = Solution()
    print(s.peakIndexInMountainArray([0,1,0]))
    print(s.peakIndexInMountainArray([0,2,1,0]))
