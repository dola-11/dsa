//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int node, stack<int>&st, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                dfs(it,st,visited,adj);
            }
        }
        st.push(node);
    }
    
    void dfsStep3(int node, vector<int> & visited, vector<vector<int>> &adjT )
    {
        visited[node] = 1;
        for(auto it: adjT[node])
        {
            if(!visited[it])
            {
                dfsStep3(it,visited,adjT);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) 
    {
        // code here
        //step 1 store all the nodes in order of their finishing times.
        int V = adj.size();
        vector<int>visited(V,0);
        stack<int>st;
        //O(V+E)
        for (int i=0; i<V; i++)
        {
            if (!visited[i])
            {
                dfs(i,st,visited,adj);
            }
        }
        
        //step 2: reverse all the edges
        //O(V+E)
        vector<vector<int>> adjT(V);
        for (int i=0; i<V; i++)
        {
            visited[i] = 0 ;         //unmark to reuse
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        
        //step 3: perform the dfs again in order of finishing times
        int scc = 0;
        //O(V+E)
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!visited[node])
            {
                scc++;
                dfsStep3(node,visited,adjT);
            }
        }
        return scc;
    }
};

| Component             | Time     | Space    |
| --------------------- | -------- | -------- |
| First DFS (topo sort) | O(V + E) | O(V)     |
| Transpose Graph       | O(V + E) | O(V + E) |
| Second DFS (on adjT)  | O(V + E) | O(V)     |
| **Total**             | O(V + E) | O(V + E) |
