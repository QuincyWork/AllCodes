
class Solution:
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        for v in A:
            size = len(v)
            for i in range(int(size/2)):
                v[i],v[size-1-i] = v[size-1-i] ^ 1, v[i] ^ 1
            
            # 奇数长度时，反转中位元素
            if (size % 2 != 0):
                v[int(size/2)] = v[int(size/2)] ^ 1
                
        return A


if __name__ == '__main__':
    s = Solution()
    result = s.flipAndInvertImage([[1,1,0],[1,0,1],[0,0,0]])
    print(result)
    result = s.flipAndInvertImage([[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]])
    print(result)
