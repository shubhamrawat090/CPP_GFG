class Solution {
  private:
    void dfs(vector<vector<char>>& grid, int i, int j, int& rows, int& cols) {
        // mark visited
        grid[i][j] = 'l';
        
        int dirs[][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };
        
        // Go in all directions and go deep into VALID neighbors
        for(auto& dir: dirs) {
            int x = i + dir[0], y = j + dir[1];
            if(x >= 0 && y >= 0 && x < rows && y < cols) {
                // within bounds
                if(grid[x][y] == 'L') {
                    // Valid land
                    dfs(grid, x, y, rows, cols);
                }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int islands = 0;
        int rows = grid.size(), cols = grid[0].size();
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 'L') {
                    dfs(grid, i, j, rows, cols);
                    islands++;
                }
            }
        }
        return islands;
    }
};