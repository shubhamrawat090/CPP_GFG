class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        // return recursive(coins, sum, n);
        vector<vector<int>> dp(n+1, vector<int>(sum + 1, -1));
        return memoized(coins, sum, n, dp);
    }
    
    int memoized(vector<int>& coins, int target, int n, vector<vector<int>>& dp) {
        if(target == 0) {
            return 1; // only way is to pick no coin
        }
        
        if(n == 1) {
            // only 1 coin left: lets say [2].
            // the only way to make target is if target % coins[0] == 0. 
            // E.g. can make target = 6 with coin 2, BUT, cannot make target = 5
            if(target % coins[n-1] == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if(dp[n][target] != -1) {
            return dp[n][target];
        }
        
        if(target >= coins[n-1]) {
            // pick + notPick
            int pick = memoized(coins, target - coins[n-1], n, dp);
            int notPick = memoized(coins, target, n-1, dp);
            return dp[n][target] = pick + notPick;
        } else {
            // notPick
            int notPick = memoized(coins, target, n-1, dp);
            return dp[n][target] = notPick;
        }
    }
    
    int recursive(vector<int>& coins, int target, int n) {
        if(target == 0) {
            return 1; // only way is to pick no coin
        }
        
        if(n == 1) {
            // only 1 coin left: lets say [2].
            // the only way to make target is if target % coins[0] == 0. 
            // E.g. can make target = 6 with coin 2, BUT, cannot make target = 5
            if(target % coins[n-1] == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if(target >= coins[n-1]) {
            // pick + notPick
            int pick = recursive(coins, target - coins[n-1], n);
            int notPick = recursive(coins, target, n-1);
            return pick + notPick;
        } else {
            // notPick
            int notPick = recursive(coins, target, n-1);
            return notPick;
        }
    }
};