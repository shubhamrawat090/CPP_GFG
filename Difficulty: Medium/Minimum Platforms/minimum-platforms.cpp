class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int platforms = 1;
        int maxPlatforms = 1;
        int start = 1, end = 0;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        while(start < n && end < n) {
            if(arr[start] <= dep[end]) {
                start++;
                platforms++;
            } else {
                end++;
                platforms--;
            }
            
            maxPlatforms = max(platforms, maxPlatforms);
        }
        
        return maxPlatforms;
    }
};
