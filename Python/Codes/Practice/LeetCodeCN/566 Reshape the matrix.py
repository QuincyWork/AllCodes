
class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        result = []
        if  len(nums) * len(nums[0]) == r * c:
            nums = [m for n in nums for m in n]
            for i in range(0,r):
                result.append([])
                for j in range(0,c):
                    result[i].append(nums.pop(0))
        else:
            result = nums

        return result
            

if __name__ == "__main__":
    s = Solution()
    print(s.matrixReshape([[1,2],[3,4]],1,4))
    print(s.matrixReshape([[1,2],[3,4]],4,1))


