class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        
        DSU(int n) {
            parent.resize(n);
            for(int i=0; i<n; i++) {
                parent[i] = i;
            }
            rank.resize(n, 0);
        }
        
        int find(int u) {
            if(parent[u] == u) return u;
            return parent[u] = find(parent[u]);
        }
        
        void unionByRank(int u, int v) {
            int pu = find(u), pv = find(v);
            
            if(pu > pv) {
                parent[pv] = pu;
            } else if(pv > pu) {
                parent[pu] = pv;
            } else { // Same rank -> RANK INCREASES
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    };
    
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> costSortedEdges;
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            costSortedEdges.push_back({w, u, v});
        }
        
        sort(costSortedEdges.begin(), costSortedEdges.end());
        
        DSU dsu(V);
        
        int sum = 0;
        for(auto& edge: costSortedEdges) {
            int u = edge[1], v = edge[2], w = edge[0];
            
            if(dsu.find(u) != dsu.find(v)) {
                sum += w; // Add up MST cost ==> You can push {u,w} if you want edge
                dsu.unionByRank(u, v);
            }
        }
        
        return sum;
    }
};