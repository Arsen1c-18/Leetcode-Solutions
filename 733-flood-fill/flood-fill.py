class Solution(object):
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        rows = len(image) #how many rows
        cols = len(image[0]) #how many cols
        og_color = image[sr][sc]
        if og_color == color:
            return image
        
        def dfs(r,c):
            if r<0 or r>=rows or c<0 or c>=cols:
                return
            if image[r][c] != og_color:
                return
            image[r][c] = color

            dfs(r+1,c)
            dfs(r-1,c)
            dfs(r,c+1)
            dfs(r,c-1)

        dfs(sr,sc)
        return image
