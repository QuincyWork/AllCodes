
class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """

        timePoints.sort()
        miniDelta = 24*60
        length = len(timePoints)
        for i in range(length):
            delta = abs(self.diffMinute(timePoints[(i-1+length) % length],timePoints[i]))
            delta = min(delta, 24*60 - delta);
            if delta < miniDelta:
                miniDelta = delta
        
        return miniDelta

    def diffMinute(self, timeA, timeB):
        A = timeA.split(':')
        B = timeB.split(':')
        return (int(B[0]) - int(A[0]))*60 + (int(B[1]) - int(A[1]))


# Test Case 
import unittest
class SolutionTest(unittest.TestCase):
    def test_all(self):
        s = Solution()
        self.assertEqual(s.findMinDifference(["23:59", "00:00"]),1)
        self.assertEqual(s.findMinDifference(["00:00","23:59", "00:00"]),0)
        self.assertEqual(s.findMinDifference(["05:31", "22:08", "00:35"]),147)
        self.assertEqual(s.findMinDifference(["17:41","22:06","20:59","17:37","04:14"]),4)
        

if __name__ == '__main__':
    unittest.main()