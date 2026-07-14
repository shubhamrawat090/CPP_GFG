class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        if(k == 0) return 0;
        int n = arr.size();
        int left = 0;
        int sum = 0;
        int maxSum = 0;
        for(int right = 0; right < n; right++) {
            sum += arr[right];
            if(right - left + 1 > k) {
                sum -= arr[left];
                left++;
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};