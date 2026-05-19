class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;
        unordered_map<char, int> charFreq;
        while(right < n) {
            charFreq[s[right]]++;
            
            while(charFreq[s[right]] > 1) {
                charFreq[s[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};
