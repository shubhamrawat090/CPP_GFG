class Solution {
    typedef pair<int, int> P;
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<P>> adj(V); // u --w--> v, adj[u] - {v, w}
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // dist[i] = distance from source to ith node
        vector<int> dist(V, INT_MAX); // Initially INT_MAX for comparison min()
        dist[src] = 0;
        
        // We need minHeap because smallest dist node is required. BASED ON DISTANCE FROM SRC
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, src});
        
        while(!q.empty()) {
            P top = q.top();
            q.pop();
            
            int d = top.first;
            int u = top.second;
            
            // If distance in queue is already greater than previous distance of node u from source 
            // then there is no need to process with that entry
            if(d > dist[u]) continue; 
            
            for(P& nbr: adj[u]) {
                int v = nbr.first;
                int w = nbr.second;
                
                // If adding going to next node (w) + existing distance dist[u] 
                // is less than what we src-> node v distance dist[v]
                // Then we abandon what we went till now(dist[v]) and update with new for node v i.e. dist[u] + w
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    q.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};