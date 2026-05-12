class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // Push all rotten oranges in queue
        int rows = mat.size(), cols = mat[0].size();
        int freshOranges = 0;
        
        queue<pair<int, int>> q;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(mat[i][j] == 2) {
                    q.push({i, j});
                } else if(mat[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        
        if(freshOranges == 0) return 0;
        
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        int timeTaken = 0;
        while(!q.empty()) {
            int size = q.size();
            timeTaken++;
            while(size--) {
                pair<int, int> top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                
                for(vector<int>& dir: dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && x < rows && y >= 0 && y < cols) { // within bounds
                        if(mat[x][y] == 1) {
                            mat[x][y] = 2;
                            freshOranges--;
                            
                            if(freshOranges == 0) return timeTaken; // At this point of time all oranges are rotten
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};