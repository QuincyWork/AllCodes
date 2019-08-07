
class Solution:
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        count = 0
        for i in range(len(grid)):
            row = grid[i]
            for j in range(len(row)):
                v = row[j]
                if v == 1:
                    if j == 0:
                        count += 1
                    else:
                        count += not row[j-1] and 1 or 0

                    if j == len(row)-1:
                        count += 1
                    else:
                        count += not row[j+1] and 1 or 0

                    if i == 0:
                        count += 1
                    else:
                        count += not grid[i-1][j] and 1 or 0

                    if i == len(grid)-1:
                        count += 1
                    else:
                        count += not grid[i+1][j] and 1 or 0

        return count                    

    def islandPerimeter1(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        count = 0
        for i in range(len(grid)):            
            for j in range(len(grid[0])):               
                if grid[i][j] == 1:
                    count += 4

                    if i > 0 and grid[i-1][j] == 1:
                        count -= 2

                    if j > 0 and grid[i][j-1] == 1:
                        count -= 2

        return count  


if __name__ == '__main__':
    s = Solution()
    print (s.islandPerimeter([[0,1,0,0], [1,1,1,0], [0,1,0,0], [1,1,0,0]]))