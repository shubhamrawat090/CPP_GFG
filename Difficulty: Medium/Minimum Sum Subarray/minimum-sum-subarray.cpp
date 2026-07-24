class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {
        // Code here
        int sum = 0;
        int minSum = INT_MAX;
        for(int num: arr) {
            sum = min(sum + num, num);
            minSum = min(minSum, sum);
        }
        return minSum;
    }
};
