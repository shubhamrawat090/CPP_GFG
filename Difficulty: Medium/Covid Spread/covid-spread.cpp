// User function Template for C++

class Solution {
  public:
    int helpaterp(vector<vector<int>> hospital) {
        // code here
        queue<pair<int, int>> q;
        int uninfectedOnes = 0;
        int rows = hospital.size(), cols = hospital[0].size();
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(hospital[i][j] == 2) {
                    q.push({i, j});
                } else if(hospital[i][j] == 1) {
                    uninfectedOnes++;
                }
            }
        }
        
        if(q.size() == 0) return 0; // No infected
        if(uninfectedOnes == 0) return 0; // No uninfected
        
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        int timeTaken = 0;
        while(!q.empty()) {
            int size = q.size();
            timeTaken++;
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                for(auto& dir: dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if(x >= 0 && x < rows && y >= 0 && y < cols) {
                        if(hospital[x][y] == 1) {
                            uninfectedOnes--;
                            hospital[x][y] = 2;
                            if(uninfectedOnes == 0) return timeTaken;
                            q.push({x, y});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};
