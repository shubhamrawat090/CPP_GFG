class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> ans;
        
        // Build adj list
        vector<vector<int>> adj(V);
        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        
        // Run DFS and fill the answer array
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++) {
            if(visited[i] == false) {
                dfs(i, adj, visited, ans);
            }
        }
        
        // Topological sort gives reverse(stack behaviour) in DFS
        if(ans.size() != V) return {};
        reverse(ans.begin(), ans.end()); 
        return ans;
    }
    
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        visited[node] = true;
        
        for(int nbr: adj[node]) {
            if(visited[nbr] == false) {
                dfs(nbr, adj, visited, ans);
            }
        }
        
        ans.push_back(node);
    }
};