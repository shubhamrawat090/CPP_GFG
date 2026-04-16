// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        // return recursive(price, n, n);
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return memoized(price, n, n, dp);
        // return tabulate(price);
        return spaceOptimize(price);
    }
    
    int spaceOptimize(vector<int>& price) {
        int n = price.size();
        
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<n+1; j++) {
                if(j >= i) {
                    int pick = price[i-1] + curr[j-i];
                    int notPick = prev[j];
                    curr[j] = max(pick, notPick);
                } else {
                    int notPick = prev[j];
                    curr[j] = notPick;
                }
            }
            prev = curr;
        }
        
        return curr[n];
    }
    
    int tabulate(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<n+1; j++) {
                if(j >= i) {
                    int pick = price[i-1] + dp[i][j-i];
                    int notPick = dp[i-1][j];
                    dp[i][j] = max(pick, notPick);
                } else {
                    int notPick = dp[i-1][j];
                    dp[i][j] = notPick;
                }
            }
        }
        
        return dp[n][n];
    }
    
    int memoized(vector<int>& price, int capacity, int rodNo, vector<vector<int>>& dp) {
        if(rodNo == 0) return 0;
        
        if(dp[rodNo][capacity] != -1) {
            return dp[rodNo][capacity];
        }
        
        if(capacity >= rodNo) {
            int pick = price[rodNo-1] + memoized(price, capacity-rodNo, rodNo, dp);
            int notPick = memoized(price, capacity, rodNo-1, dp);
            return dp[rodNo][capacity] = max(pick, notPick);
        } else {
            int notPick = memoized(price, capacity, rodNo-1, dp);
            return dp[rodNo][capacity] = notPick;
        }
    }
    
    int recursive(vector<int>& price, int capacity, int rodNo) {
        if(rodNo == 0) return 0;
        
        if(capacity >= rodNo) {
            int pick = price[rodNo-1] + recursive(price, capacity-rodNo, rodNo);
            int notPick = recursive(price, capacity, rodNo-1);
            return max(pick, notPick);
        } else {
            int notPick = recursive(price, capacity, rodNo-1);
            return notPick;
        }
    }
};