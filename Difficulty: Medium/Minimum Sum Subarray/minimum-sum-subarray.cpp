class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {
        // Code here
        int sum = 0;
        int minSum = INT_MAX;
        for(int num: arr) {
            sum += num;
            minSum = min(sum, minSum);
            if(sum > 0) sum = 0;
        }
        return minSum;
    }
};
