"""
今天，书店老板有一家店打算试营业 customers.length 分钟。每分钟都有一些顾客（customers[i]）会进入书店，所有这些顾客都会在那一分钟结束后离开。

在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。 当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 X 分钟不生气，但却只能使用一次。

请你返回这一天营业下来，最多有多少客户能够感到满意的数量。
 

示例：

输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
输出：16
解释：
书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.
 

提示：

1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1

"""

from typing import List

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        
        # 把抑制生气时间作为一个窗口，计算每一分钟窗口的客户好感增值的最大值
        # 返回 本来好感的客户数+抑制生气带来的客户好感的最大增值
        delta = 0;
        total = 0;
        for i in range(0,X):
            if grumpy[i] == 1:
                delta += customers[i]
            else:
                total += customers[i];
        
        current = delta
        # 把生气窗口往后移,计算新窗口的增值
        for i in range(X,len(grumpy)):
            if grumpy[i-X] == 1:
                current -= customers[i-X]

            if grumpy[i] == 1:
                current += customers[i]
            else:
                total += customers[i]

            delta = max(current,delta);

        return total + delta;


if __name__=='__main__':
    s = Solution()
    assert s.maxSatisfied([1,0,1,2,1,1,7,5],[0,1,0,1,0,1,0,1],3) == 16