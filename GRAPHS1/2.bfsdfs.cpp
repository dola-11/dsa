class Solution {
  public:
    void dfsHelper(int node, vector<int> adj[], vector<int>& visited, vector<int>&dfs)
    {
      visited[node] = 1;
      dfs.push_back(node);

      for (auto it : adj[node])
      {
        if(!visited[it])
        {
          dfsHelper(it, adj, visited, dfs);
        }
      }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
      vector<int> visited(V,0);
      vector<int> dfs;
      dfsHelper(0,adj,visited,dfs);
     return dfs;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int> visited(V,0);
        visited[0]=1;
        queue<int> q;
        q.push(0);
        vector<int>bfs;
        while(!q.empty())
        {
          int node = q.front();
          q.pop();
          bfs.push_back(node);

          for (auto it: adj[node])
          {
            if(!visited[it])
            {
              visited[it] = 1;
              q.push(it);
            }
          }
        }
        return bfs;
    }
};
