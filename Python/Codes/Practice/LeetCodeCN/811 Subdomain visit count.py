
class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        result = {}
        for v in cpdomains:
            count,addr = v.split(' ')
            count = int(count)            
            result[addr] = result.get(addr,0) + count
            for i,v in enumerate(addr):
                if v == '.':
                    sub = addr[i+1:]
                    result[sub] = result.get(sub,0) + count
        
        return [str(value) + " " + key for key,value in result.items()]

        

if __name__ == '__main__':
    s = Solution()
    print(s.subdomainVisits(["9001 discuss.leetcode.com"]))
    print(s.subdomainVisits(["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]))