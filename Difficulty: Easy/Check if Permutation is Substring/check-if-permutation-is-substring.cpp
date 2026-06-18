// User function Template for C++
class Solution {
  public:
    bool search(string& s2, string& s1) {
        // Write your code here
        int freq[26] = {0};
        for(char ch: s1) {
            freq[ch-'a']--;
        }

        int count = 0;
        int left = 0, right = 0;
        int n = s2.size();
        while(right < n) {
            if(freq[s2[right]-'a'] < 0) {
                count++; // char from s1
            }

            freq[s2[right]-'a']++;

            while(count == s1.size()) {
                int windowSize = right-left+1;
                if(windowSize == s1.size()) {
                    // Out window is an permuation of s1
                    return true; 
                }

                // shrink from left
                freq[s2[left]-'a']--;
                if(freq[s2[left]-'a'] < 0) {
                    // char from s1 is NOT in my window
                    count--;
                }
                left++;
            }

            right++;
        }
        return false;
    }
};