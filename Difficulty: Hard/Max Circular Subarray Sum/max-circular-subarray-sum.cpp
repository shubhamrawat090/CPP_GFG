class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int totalSum = 0;
        for(int num: arr) {
            totalSum += num;
        }
        int minSum = getMinSum(arr);
        int circularSum = totalSum - minSum;
        int maxSum = getMaxSum(arr);
        return maxSum < 0 ? maxSum : max(maxSum, circularSum);
    }
    
    int getMaxSum(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for(int num: nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
    
    int getMinSum(vector<int>& nums) {
        int sum = 0, minSum = INT_MAX;
        for(int num: nums) {
            sum += num;
            minSum = min(minSum, sum);
            if(sum >= 0) sum = 0;
        }
        return minSum;
    }
};