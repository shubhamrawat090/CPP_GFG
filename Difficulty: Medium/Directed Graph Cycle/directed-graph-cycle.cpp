class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> graph(V);
        vector<int> indegree(V);
        
        for(vector<int> edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        // Find topological sort and check if length of topo == V or not
        vector<int> topo;
        queue<int> q;
        
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Kahn's Algo - Topological Sort
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            
            topo.push_back(top);
            
            for(int nbr: graph[top]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        
        return topo.size() != V;
    }
};