
class Solution:

    #编码表
    codec = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        record = set()
        for v in words:
            encode = ""
            for i in v:
                encode += self.codec[ord(i) - ord('a')]

            record.add(encode)

        return len(record)



if __name__ == '__main__':
    s = Solution()
    print(s.uniqueMorseRepresentations(["gin", "zen", "gig", "msg"]))
