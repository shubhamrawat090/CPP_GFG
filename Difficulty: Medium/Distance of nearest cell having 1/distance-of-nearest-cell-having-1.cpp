class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1; // Not visited
                }
            }
        }
        
        int dist = 0;
        int dirs[][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        while(!q.empty()) {
            int size = q.size();
            dist++;
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                for(auto& dir: dirs) {
                    int x = dir[0] + i, y = dir[1] + j;
                    if(x < 0 || y < 0 || x == rows || y == cols) continue;
                    if(grid[x][y] != -1) continue;
                    grid[x][y] = dist;
                    q.push({x, y});
                }
            }
        }
        return grid;        
    }
};