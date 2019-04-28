class Solution:
    grid = None
    map_length = None
    map_ = None

    def dfs(self, y, x):
        if (x + y) % 2 == 0 or \
                not 0 <= y < self.map_length or \
                not 0 <= x < self.map_length or \
                self.map_[y][x]:
            return 0
        self.map_[y][x] = 1
        
        if 0 <= y - 1 < self.map_length and \
                0 <= x - 1 < self.map_length and \
                not self.map_[y - 1][x - 1] and \
                self.grid[(y - 1) // 2][(x - 1) // 2] != '/':
            # 左上
            self.dfs(y-1, x-1) 
        if 0 <= y - 1 < self.map_length and \
                0 <= x + 1 < self.map_length and \
                not self.map_[y - 1][x + 1] and \
                self.grid[(y - 1) // 2][x // 2] != '\\':
            # 右上
            self.dfs(y-1, x+1)  
        if 0 <= y + 1 < self.map_length and \
                0 <= x - 1 < self.map_length and \
                not self.map_[y + 1][x - 1] and \
                self.grid[y // 2][(x - 1) // 2] != '\\':
            # 左下
            self.dfs(y+1, x-1)
        if 0 <= y + 1 < self.map_length and \
                0 <= x + 1 < self.map_length and \
                not self.map_[y + 1][x + 1] and \
                self.grid[y // 2][x // 2] != '/':
            # 右下
            self.dfs(y+1, x+1)
        return 1
    
    def regionsBySlashes(self, grid: List[str]) -> int:
        answer = 0

        self.grid = grid
        self.map_length = len(grid) *2 + 1
        self.map_ = [[0] * self.map_length for _ in range(self.map_length)]
        
        for i in range(self.map_length):
            for j in range(self.map_length):
                answer += self.dfs(i, j)
        
        return answer
