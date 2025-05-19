class Solution{
public:
    bool dfsCheck(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto it : adj[node])
        {
            if (visited[it]!= 1)
            {
                if (dfsCheck(it,adj, visited, pathVisited) == true) return true;
            }
            else if (visited[it] == 1 && pathVisited[it] == 1)
            {
                return true;
            }
        }

        pathVisited[node] = 0;
        return false;
    }
    bool isCyclic(int N, vector<int> adj[]) 
    {
        vector<int>visited(N,0);
        vector<int>pathVisited(N,0);

        for (int i = 0; i<N; i++)
        {
            if (!visited[i])
            {
                if (dfsCheck(i, adj, visited, pathVisited) == true) return true;
            }
        }
        return false;
    }
};

//TC : O(V+E)
//SC : O(V + V + V), visited[] array → O(V), pathVisited[] array → O(V), Recursion call stack (in worst case, depth = V) → O(V)

//CAN DO WITH ONE ONE VISITED ARRAY, THAT WAY WE HAVE MARK IT 1 FOR VISITED AND 2 FOR PATHVISITD.
