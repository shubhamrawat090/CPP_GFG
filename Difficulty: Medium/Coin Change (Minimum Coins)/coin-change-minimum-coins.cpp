class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // NOTE: We return the number of coins
        int n = coins.size();
        // return recursive(coins, sum, n);
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        int ans = memoized(coins, sum, n, dp);
        return ans >= 1e9 ? -1 : ans;
    }
    
    int memoized(vector<int>& coins, int sum, int n, vector<vector<int>>& dp) {
        if(sum == 0) return 0;
        
        if(n == 1) {
            // For impossible case we return infinitu instead of 0 for handling min()
            return sum % coins[n-1] == 0 ? sum / coins[n-1] : 1e9;
        }
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(sum >= coins[n-1]) {
            int pick = 1 + memoized(coins, sum-coins[n-1], n, dp);
            int notPick = memoized(coins, sum, n-1, dp);
            return dp[n][sum] = min(pick, notPick);
        } else {
            return dp[n][sum] = memoized(coins, sum, n-1, dp);
        }
    }
    
    int recursive(vector<int>& coins, int sum, int n) {
        // base case
        if(sum == 0)
            return 0;   // 0 coins needed to make sum 0
    
        if(n == 1) {
    
            // only one coin available
            if(sum % coins[0] == 0)
                return sum / coins[0];   // take that coin multiple times
    
            return 1e9;  // impossible case
        }
    
        int notPick = recursive(coins, sum, n-1);
    
        int pick = 1e9;
    
        if(sum >= coins[n-1])
            pick = 1 + recursive(coins, sum - coins[n-1], n);
    
        return min(pick, notPick);
    }
};