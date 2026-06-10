class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int count = 0;
        int sum = 0;
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        for(int num: arr) {
            sum += num;
            int toFind = sum - k;
            count += sumCount[toFind];
            sumCount[sum]++;
        }
        return count;
    }
};