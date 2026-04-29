class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(vector<int> edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, pathVisited)) return true;
            }
        }
        return false;
    }
    
    bool dfs(
        int node, 
        vector<vector<int>>& adj, 
        vector<int>& visited, 
        vector<int>& pathVisited
    ) {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        for(int nbr: adj[node]) {
            if(!visited[nbr]) {
                if(dfs(nbr, adj, visited, pathVisited)) return true;
            } else if(pathVisited[nbr]) {
                return true;
            }
        }
        
        pathVisited[node] = 0; // backtrack
        
        return false;
    }
};