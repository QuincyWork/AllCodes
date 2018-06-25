
class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        x = 0;
        y = 0;
        for v in moves:
            if v == 'U':
                y += 1
            elif v == 'D':
                y -= 1
            elif v == 'R':
                x += 1
            elif v == 'L':
                x -= 1

        return x == 0 and y == 0


if __name__ == '__main__':
    s = Solution()
    print(s.judgeCircle("UD"));
    print(s.judgeCircle("LL"));