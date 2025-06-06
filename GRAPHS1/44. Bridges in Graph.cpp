class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges) 
        {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) 
        {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);                //after the dfs traversal the parent node checks for the low
                // node --- it (checking if this can be a bridge)
                if (low[it] > tin[node])        //if(low[it] <= tin[node]) then it can reach
                {
                    bridges.push_back({it, node});
                }
            }
            else 
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>>adj(n);
        for (auto it : connections) 
        {
            int u = it[0]; 
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};

| Component        | Complexity               |
| ---------------- | ------------------------ |
| Time Complexity  |   O(V + 2E)              |
| Space Complexity |   O(V + 2E) + O(3N)      |
| Algorithm Used   | Tarjan's DFS for Bridges |
