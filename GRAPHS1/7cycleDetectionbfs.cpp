class Solution {
  public:
    bool detect(int src, vector<vector<int>>& adj, vector<int>& visited) {
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (int adjacentNode : adj[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if (adjacentNode != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for (auto& e : edges) {
            if (e.size() < 2) continue; // Prevent out-of-bounds access
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detect(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

//TC : O(V+E)
//SC : O(V+E)
