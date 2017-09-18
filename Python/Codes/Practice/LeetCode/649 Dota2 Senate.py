
class Solution:
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """
        
        banSenate = ''        
        while len(set(senate)) > 1:
            
            remainSenate = ''
            for val in senate:
                if banSenate and banSenate[0] == val:             
                    banSenate = banSenate[1:]
                else:
                    if val == 'R':
                        banSenate += 'D'
                    else:
                        banSenate += 'R'

                    remainSenate += val
            
            senate = remainSenate
           
        return {'D':"Dire",'R':"Radiant"}[senate[0]]
            

if __name__ == '__main__':

    solution = Solution()
    print(solution.predictPartyVictory('RD'))
    print(solution.predictPartyVictory('RDD'))
    print(solution.predictPartyVictory('RDDRDRDDDRDDRRRDR'))