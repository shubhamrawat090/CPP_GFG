class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> visited(V, 0);
        
        vector<vector<int>> graph(V);
        for(vector<int> edge: edges) {
            int u = edge[0], v = edge[1];
            // undirected so, u<---->v both
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                vector<int> connectedNodes;
                dfs(graph, i, visited, connectedNodes);
                ans.push_back(connectedNodes);
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, int node, vector<int>& visited, vector<int>& connectedNodes) {
        visited[node] = 1;
        connectedNodes.push_back(node);
        
        for(int nbr: graph[node]) {
            if(!visited[nbr]) {
                dfs(graph, nbr, visited, connectedNodes);
            }
        }
    }
};
