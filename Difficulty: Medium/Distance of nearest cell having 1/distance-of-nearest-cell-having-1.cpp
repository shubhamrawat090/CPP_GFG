class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, -1));
        queue<pair<int, int>> q;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 1) {
                    visited[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        int dist = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                for(auto& dir: dirs) {
                    int x = dir[0] + i, y = dir[1] + j;
                    if(x >= 0 && x < rows && y >= 0 && y < cols) {
                        if(visited[x][y] == -1) {
                            visited[x][y] = dist + 1;
                            q.push({x, y});
                        }
                    }
                }
            }
            dist++;
        }
        
        return visited;
    }
};