class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        vector<unordered_set<char>> adj(26);
        
        unordered_map<char, int> indegree;
        unordered_set<char> uniqueChars;
        for(int i=0; i<n; i++) {
            for(int j=0; j<words[i].size(); j++) {
                uniqueChars.insert(words[i][j]);
                indegree[words[i][j]] = 0;
            }
        }
        
        for(int i=1; i<n; i++) {
            string prev = words[i-1], curr = words[i];
            int minLen = min(prev.size(), curr.size());
            bool found = false;
            for(int j=0; j<minLen; j++) {
                if(prev[j] != curr[j]) {
                    found = true;
                    // u = prev[j], v = curr[j] ==> u-->v
                    adj[prev[j]-'a'].insert(curr[j]);
                    break; // DO not proceed further
                    
                    // CAN NOT CALCULATE INDEGREE HERE BECAUSE OF DUPLICATE NODES
                }
            }
            if(!found && minLen != prev.size()) {
                // prev string has 1 extra char and no dissimilarity is found
                // prev = abcd, curr = abc ==> this means d > ''. WHICH IS IMPOSSIBLE
                return "";
            }
        }
        
        // Calculate indegree
        for(char u: uniqueChars) {
            for(char v: adj[u-'a']) {
                indegree[v]++;
            }
        }
        
        // GET topological sort
        string topo = "";
        
        queue<char> q;
        
        for(auto& indeg: indegree) {
            if(indeg.second == 0) {
                q.push(indeg.first);
            }
        }
        
        while(!q.empty()) {
            char top = q.front();
            q.pop();
            topo.push_back(top);
            for(char nbr: adj[top - 'a']) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        
        return topo.size() != uniqueChars.size() ? "" : topo;
    }
};