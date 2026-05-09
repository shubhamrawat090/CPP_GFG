class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        if(knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1]) return 0;
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({knightPos[0]-1, knightPos[1]-1});
        visited[knightPos[0]-1][knightPos[1]-1] = 1;
        int dist = 0;
        vector<vector<int>> dirs = {
            {-1, -2},
            {-2, 1},
            {-1, 2},
            {1, 2},
            {2, 1},
            {2, -1},
            {1, -2},
            {-2, -1}
        };
        while(!q.empty()) {
            int size = q.size();
            dist++;
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                for(auto& dir: dirs) {
                    int x = dir[0] + i, y = dir[1] + j;
                    if(x == targetPos[0]-1 && y == targetPos[1]-1) {
                        return dist;
                    }
                    if(x >= 0 && x < n && y >= 0 && y < n) {
                        if(!visited[x][y]) {
                            q.push({x, y});
                            visited[x][y] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};