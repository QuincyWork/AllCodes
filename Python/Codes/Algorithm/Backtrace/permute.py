"""
全排序
"""

class Solution :
    def permute(self,nums):
        trace = []
        self.backtrace(nums,trace);

    def backtrace(self,nums,trace):
        if len(trace) == len(nums):
            print(trace)
            return

        for num in nums:
            if trace.count(num) > 0:
                continue
            
            #选择一个
            trace.append(num)
            self.backtrace(nums,trace)
            #撤销选择
            trace.pop()


if __name__=='__main__':
    s = Solution()
    nums = ['A','B','C','D']
    s.permute(nums)