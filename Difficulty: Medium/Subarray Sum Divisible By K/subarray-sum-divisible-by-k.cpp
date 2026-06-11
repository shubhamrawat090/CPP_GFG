class Solution {
public:
    int subCount(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        long long prefixSum = 0;
        long long count = 0;

        freq[0] = 1;

        for(int x : nums) {
            prefixSum += x;

            int rem = prefixSum % k;

            if(rem < 0)
                rem += k;

            count += freq[rem];
            freq[rem]++;
        }

        return count;
    }
};