class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char, int> freq;
        int maxLen = -1;
        int left = 0;
        int n = s.size();
        for(int right=0; right<n; right++) {
            freq[s[right]]++;
            while(freq.size() > k) {
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            if(freq.size() == k) maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};