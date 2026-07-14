class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        vector<int> freq(26, 0);
        int n = s.size();
        int left = 0;
        int maxLen = -1;
        for(int right=0; right<n; right++) {
            freq[s[right]-'a']++;
            
            while(uniqueCharCount(freq) > k) {
                freq[s[left]-'a']--;
                left++;
            }
            
            if(uniqueCharCount(freq) == k) {
                maxLen = max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
    
    int uniqueCharCount(vector<int>& freq) {
        int sum = 0;
        for(int i=0; i<26; i++) {
            int f = freq[i];
            if(f >= 1) sum++;
        }
        
        return sum;
    }
};