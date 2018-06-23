
class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for v in A:
            size = len(v)
            for i in range(size/2):
                v[i],v[size-1-i] = v[size-1-i] ^ 0, v[i] ^ 0

        return A

