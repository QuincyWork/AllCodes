
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        self.quickSort(nums,0,len(nums)-1)
        
    
    def quickSort(self,nums,left,right):
        """
        """
        if left < right:
            pivot = self.partition(nums,left,right)
            self.quickSort(nums,left,pivot-1)
            self.quickSort(nums,pivot+1,right)


    def partition(self,nums,left,right):
        """
        """
        pivot = (left + right)/2
        nums[pivot],nums[right] = nums[right],nums[pivot]
        pos = left
        for i in range(left,right):
            if nums[i] <= nums[right]:
                nums[pos],nums[i] = nums[i],nums[pos]
                pos += 1

        nums[pos],nums[right] = nums[right],nums[pos]
        return pivot
