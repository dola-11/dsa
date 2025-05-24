class Solution {
  public:
    bool isSafe(int node, vector<int>colour, bool graph[101][101], int N, int col)
    {
        for (int k =0; k<N; k++)
        {
            //skip self nodes, check if k is connected to node and finally see if they have the same colour.
            if (k!=node && graph[k][node] && colour[k] == col) return false;
        }
        return true;
    }
    
    bool solve(int node, vector<int>colour, int m, int N, bool graph[101][101])
    {
        if (node == N) return true;

      //iterating through the colour options.
        for (int i=1; i<=m; i++)
        {
            //pass the current colour into the isSafe function.
            if (isSafe(node,colour,graph,N,i))
            {
                colour[node] = i;
                
                if(solve(node+1,colour,m,N,graph) == true) return true;
                
                colour[node] = 0;
            }
        }
        return false;
    }
    
    bool colouring(bool graph[101][101], int m, int N)
    {
        vector<int>colour(N,0);
        return solve(0, colour, m, N, graph);
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        bool graph[101][101] = {false};
        
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u][v] = true;
            graph[v][u] = true;
            //since it is an undirected graph
        }
        
        return colouring(graph,m,v);
    }
};

//TC : O(V * m^V) = O(m^V) 
//SC : O(V)
