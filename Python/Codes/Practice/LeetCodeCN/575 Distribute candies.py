
class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        cand = set()
        for v in candies:
            cand.add(v)

        return min(len(cand), int(len(candies)/2))

    def distributeCandies1(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        cand = set(candies)        
        return min(len(cand), len(candies)//2)

if __name__ == '__main__':
    s = Solution();
    print(s.distributeCandies1([1,1,2,2,3,3]))
    print(s.distributeCandies1([1,1,2,3]))
