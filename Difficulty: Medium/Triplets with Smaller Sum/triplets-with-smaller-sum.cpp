class Solution {
  public:
    int countTriplets(int target, vector<int>& nums) {
        // code here
        // APPROACH - All sums are being generated in normal 3 sum ---> just get the closest sum to target
        int n = nums.size();
        sort(nums.begin(), nums.end()); // N log N

        int minSumCount = 0;

        for (int first = 0; first < n - 2; first++) { // N
            int second = first + 1, third = n - 1;
            while (second < third) { // N / 2 ==> N
                int sum = nums[first] + nums[second] + nums[third];

                if (sum == target) {
                    third--;
                    // CANNOT DO second++ because that increases sum
                } else if (sum > target) {
                    third--;
                } else {
                    // sum < target
                    // first, second ......,    third is LESS
                    // first, second .....third-1, third is ALSO LESS
                    minSumCount += (third-second);
                    second++;
                }
                
            }
        }
        return minSumCount;
    }
};