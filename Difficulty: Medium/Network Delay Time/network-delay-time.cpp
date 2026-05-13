class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src}); // Dist, node
        
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto top = q.top();
                q.pop();
                int d = top.first, node = top.second;
                
                if(d > dist[node]) continue;
                
                for(auto nbr: adj[node]) {
                    int nbrNode = nbr.first;
                    int nbrWeight = nbr.second;
                    if(dist[node] + nbrWeight < dist[nbrNode]) {
                        dist[nbrNode] = dist[node] + nbrWeight;
                        q.push({dist[nbrNode], nbrNode});
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<V; i++) {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};