class Solution {
  public:
    string minWindow(string &s, string &p) {
        // s = ABCAND, p = ABC
        // map freq map of p --> as +ve AND a charCount = p.size()
        // map: {A:1, B:1, C:1}, charCount = 3
        // left = 0, right = 0;
        // In a while loop: Traversing chars of 's'
        // if BEFORE DECREASE map[s[right]] > 0, then it is part of SMALL STR: p
        // so, do charCount--
        // map[s[right]]--; always decrease freq for chars of s
        // if charCount < 0, then it means you have counted counted all chars of p
        // in a while(charCount == 0): As soon as all chars of p are counted
        // SHRING LEFT WINDOW FROM HERE AS MUCH
        // map[s[left]]++
        // left++
        // if range(right-left+1) < minRANGE: get the current left(starting index of substr), and minLen = range
        
        int left = 0, right = 0;
        unordered_map<char, int> charFreq;
        for(char ch: p) {
            charFreq[ch]++;
        }
        int charCount = p.size();
        int minRange = INT_MAX, index = -1;
        while(right < s.size()) {
            if(charFreq[s[right]] > 0) charCount--;
            charFreq[s[right]]--;
            
            while(charCount == 0) {
                int range = right-left+1;
                if(range < minRange) {
                    index = left;
                    minRange = range;
                }
                
                charFreq[s[left]]++;
                if(charFreq[s[left]] > 0) charCount++;
                left++;
            }
            
            right++;
        }
        return index == -1 ? "" : s.substr(index, minRange);
    }
};