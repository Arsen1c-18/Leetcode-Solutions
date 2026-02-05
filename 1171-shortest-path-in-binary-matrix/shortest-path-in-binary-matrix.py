import heapq

class Solution:
    def shortestPathBinaryMatrix(self, grid):
        n = len(grid)
        if grid[0][0] or grid[n-1][n-1]:
            return -1
        
        dirs = [(1,0),(-1,0),(0,1),(0,-1),(1,1),(1,-1),(-1,1),(-1,-1)]
        
        def h(r, c):
            return max(abs(n-1-r), abs(n-1-c))  # Chebyshev
        
        # distance (g cost)
        dist = [[float('inf')] * n for _ in range(n)]
        dist[0][0] = 1
        
        pq = [(1 + h(0,0), 1, 0, 0)]  # (f, g, r, c)
        
        while pq:
            f, g, r, c = heapq.heappop(pq)
            
            if (r, c) == (n-1, n-1):
                return g
            
            # IMPORTANT: skip outdated states
            if g > dist[r][c]:
                continue
            
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                
                if 0 <= nr < n and 0 <= nc < n and grid[nr][nc] == 0:
                    ng = g + 1
                    
                    if ng < dist[nr][nc]:
                        dist[nr][nc] = ng
                        heapq.heappush(pq, (ng + h(nr,nc), ng, nr, nc))
        
        return -1
