class Solution {
  public:
    void dfs(int node, vector<vector<int>>&adjList, vector<bool> &visited)
    {
      visited[node] = true;
      for (int neighbour : adjList[node])
      {
        if(!visited[neighbour])
        {
          dfs(neighbour, adjList, visited);
        }
      }
    }
    int findNumberOfComponent(int E, int V, vector<vector<int>> &edges) 
    {
      vector<vector<int>>adjList(V);
      for (auto &edge: edges)
      {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      int noOfComponents = 0;
      vector<bool>visited(V,false);

      for (int i=0; i<V; i++)
      {
        if (!visited[i])
        {
          noOfComponents ++;
          dfs(i,adjList,visited);
        }
      }
      return noOfComponents;
    }
};
