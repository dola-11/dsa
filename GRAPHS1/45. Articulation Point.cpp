class Solution {
  public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &visited, vector<int>&tin, vector<int>&low, vector<int> &mark, vector<int> adj[])
    {
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        int child = 0;
        
        for (auto it:adj[node])
        {
            if (it == parent) continue;
            if (!visited[it])
            {
                dfs(it, node, visited, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node],tin[it]);
            }
        }
        if (parent == -1 && child > 1)
        {
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) 
    {
        // Code here
        vector<int>visited(V,0);
        vector<int> tin(V,0);
        vector<int> low(V,0);
        
        vector<int>mark(V,0);
        
        for (int i=0; i<V; i++)
        {
            if (!visited[i])
            {
                dfs(i,-1,visited,tin,low,mark,adj);
            }
        }
        
        vector<int>ans;
        for (int i=0; i<V; i++)
        {
            if (mark[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) return {-1};
        return ans;
    }
};

| Metric    | Complexity               |
| --------- | ----------               |
| **Time**  | `O(V + E) + O(V) + O(4V)`|
| **Space** | `O(V + E)`               |

/*
Intuition Behind the Difference
Bridge: There is no alternate path to reach an ancestor — removing the edge breaks connectivity.

Articulation Point: There is no alternate way to reach ancestors through other children — removing the node breaks connectivity.

Practical Use
Use Tarjan’s Bridge version if you need to identify vulnerable connections (like cables, roads, etc.)

Use Tarjan’s Articulation Point version to find vulnerable nodes (like routers, hubs, servers)
*/
