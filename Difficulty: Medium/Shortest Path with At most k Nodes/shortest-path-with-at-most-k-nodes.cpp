class Solution {
  public:
    int findCheapestCost(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
        
        // {stops, {node, weight}} in queue
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            
            int stops = top.first, node = top.second.first, weight = top.second.second;
            
            if(stops > k) continue; // No need of stops > k
            
            for(auto& nbr: adj[node]) {
                int nbrNode = nbr.first, nbrWeight = nbr.second;
                if(stops <= k) { // allow till k as nbr can be destination as well
                    if(weight + nbrWeight < dist[nbrNode]) {
                        dist[nbrNode] = weight + nbrWeight;
                        q.push({stops+1, {nbrNode, dist[nbrNode]}});
                    }
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};