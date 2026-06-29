class Solution {
	public:
	int countConnected(int V, vector<vector<int>> & edges) {
		// code here
		vector<vector<int>> isConnected(V, vector<int>(V, 0));
		for(auto& edge: edges) {
		    isConnected[edge[0]][edge[1]] = 1;
		    isConnected[edge[1]][edge[0]] = 1;
		}
		int n = isConnected.size();
        vector<int> visited(n, 0);
        int count = 0;
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, isConnected, visited, n);
                count++;
            }
        }
        return count;
	}
	
	void dfs(int node, vector<vector<int>> & isConnected, vector<int>& visited, int& n) {
		visited[node] = 1;
		for (int i = 0; i<n; i++) {
			if (node == i)
				continue;
			if (isConnected[node][i] && !visited[i]) {
				dfs(i, isConnected, visited, n);
			}
		}
	}
};
