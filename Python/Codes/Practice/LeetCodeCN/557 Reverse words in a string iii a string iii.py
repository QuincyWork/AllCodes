
class Solution:
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split(' ')
        for i,v in enumerate(words):
            words[i] = v[::-1]

        return ' '.join(words)


if __name__ == '__main__':
    s = Solution()
    print(s.reverseWords("Let's take LeetCode contest"));