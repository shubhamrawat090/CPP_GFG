class Solution {
	public:
	int maxSubarraySum(vector<int>& arr, int k) {
		// code here
		int n = arr.size();
		int left = 0;
		int sum = 0;
		int maxSum = INT_MIN;
		for (int right = 0; right<n; right++) {
			sum += arr[right];
			while (right - left + 1 > k) {
				sum -= arr[left];
				left++;
			}
			maxSum = max(maxSum, sum);
		}
		return maxSum;
	}
};
