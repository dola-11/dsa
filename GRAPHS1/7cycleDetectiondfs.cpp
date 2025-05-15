class Solution {
  public:
    bool dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for (auto adjacentNode : adj[node])
        {
            if (!visited[adjacentNode])
            {
               if (dfs(adjacentNode, node, visited, adj)== true)
               {
                   return true;
               }
            }
            else if (adjacentNode != parent)
            {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(V);
        vector<int>visited(V,0);
        
        for (auto edge : edges)
        {
            if (edge.size()<2) continue;
            
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i=0; i<V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i,-1,visited,adj) == true) return true;
            }
        }
        return false;
    }
};

//SC : O(N)
//TC : O(N+E)
