"""
给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：

	二叉树的根是数组 nums 中的最大元素。
	左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
	右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
	返回有给定数组 nums 构建的 最大二叉树 。

	提示：

	1 <= nums.length <= 1000
	0 <= nums[i] <= 1000
	nums 中的所有整数 互不相同

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/maximum-binary-tree
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

	输入：nums = [3,2,1,6,0,5]
	输出：[6,3,5,null,2,0,null,null,1]
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    
    def constructMaximumBinaryTree(self, nums) -> TreeNode:
        return self.constructSubMaximumBinaryTree(nums,0,len(nums)-1)

    def constructSubMaximumBinaryTree(self, nums, left, right):
        
        if left > right:
            return None

        max = left
        maxVal = nums[left]
        for i in range(left,right+1):
            if nums[i] > maxVal:
                max = i
                maxVal = nums[i]

        root = TreeNode(maxVal)
        root.left = self.constructSubMaximumBinaryTree(nums,left,max-1)
        root.right = self.constructSubMaximumBinaryTree(nums,max+1,right)
        return root


if __name__=="__main__":
    s = Solution()
    data = [3,2,1,6,0,5]
    result = s.constructMaximumBinaryTree1(data)
    #result = s.constructMaximumBinaryTree(data)
    data = [3,2,1]
    result = s.constructMaximumBinaryTree(data)