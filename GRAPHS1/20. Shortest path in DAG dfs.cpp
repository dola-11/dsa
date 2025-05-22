class Solution {
  public:
    void topo(int node, vector<int> &visited, vector<vector<pair<int,int>>> &adj, stack<int>&st)
    {
        visited[node] = 1;
        
        for (auto it: adj[node])
        {
            int neighbour = it.first;
            if (!visited[neighbour])
            {
                topo(neighbour,visited,adj,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) 
    {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for (int i=0; i<E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
            
        vector<int>visited(V,0);
        stack<int>st;
            
        for (int i=0; i<V; i++)
        {
            if (!visited[i])
            {
                topo(i,visited,adj,st);
            }
        }
            
        vector<int>dist(V,1e9);
        dist[0] = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
        
            if (dist[node] != 1e9)
            {
                for (auto it: adj[node])
                {
                    int v = it.first;
                    int wt = it.second;
                        
                    if (dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        for (int i = 0; i < V; i++) 
        {
            if (dist[i] == 1e9) dist[i] = -1;
        }
            
        return dist;
    }
};

//TC : O(V+E) + O(V+E) + O(E) = O(V + E)
//SC : O(V+E) + O(V) + O(V) + O(V) = O(V+E)
