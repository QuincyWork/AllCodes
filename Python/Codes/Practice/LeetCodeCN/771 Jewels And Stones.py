

class Solution:
	def numJewelsInStones(self, J, S):
		"""
		:type J: str
		:type S: str
		:rtype: int
		"""
		count = 0
		cachedTbl = [False] * 256
		for i in J:
			cachedTbl[ord(i)] = True

		for i in S:
			if cachedTbl[ord(i)]:
				count+=1

		return count



if __name__ == '__main__':

	s = Solution()    
	print(s.numJewelsInStones("aA","aAAbbbb"));
	print(s.numJewelsInStones("z","ZZ"));
	print(s.numJewelsInStones("",""));
	print(s.numJewelsInStones("Abcdf","afca1wdfAffaFDab"));

