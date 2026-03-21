class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        n = len(grid[0])
        if k <= (n + 1)//2:
            for j in range(k//2):
                toprow = grid[x+j]
                bottomrow = grid[x+k-1-j]
                for i in range(y,y+k):
                    toprow[i],bottomrow[i] = bottomrow[i],toprow[i]
        else:
            for j in range(k//2):
                t_ind, b_ind = x+j, x+k-1-j 
                toprow = grid[t_ind]
                bottomrow = grid[b_ind]
                for i in range(y):
                    toprow[i], bottomrow[i] = bottomrow[i], toprow[i]
                for i in range(y+k,n):
                    toprow[i], bottomrow[i] = bottomrow[i], toprow[i]
                grid[t_ind], grid[b_ind] = grid[b_ind], grid[t_ind]
        return grid
