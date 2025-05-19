//Method 1: BFS using multiple vectors
class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> & visited, vector<int>&pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfsCheck(it,adj,visited,pathVisited)) return true;
            }
            else if (pathVisited[it])
            {
                return true;
            }
        }

        pathVisited[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<int>visited(numCourses, 0);
        vector<int>pathVisited(numCourses, 0);

        for (int i=0; i<numCourses; i++)
        {
            if (!visited[i])
            {
                if (dfsCheck(i,adj,visited,pathVisited)) return false;
            }
        }
        return true;
    }
};

//TC : O(V+E)
//SC : O(E) + O(V+V) + O(V) ~ O(V+E)

//Method 2: BFS using less vectors
class Solution {
public:
    bool dfs(int node, vector<vector<int>> & adj, vector<int> &state)
    {
        state[node] = 1;

        for (int neighbour : adj[node])
        {
            if (state[neighbour] == 0) 
            {
                    if (dfs(neighbour, adj, state))  
                    return true;
            }
            else if (state[neighbour] == 1)
            {
                return true;
            }
        }
        state[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        for (const auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<int>state(numCourses,0);
        for (int i=0; i<numCourses; i++)
        {
            if(state[i] == 0)
            {
                if (dfs(i, adj, state)) return false;
            }
        }
        return true;
    }
};

//TC : O(V+E)
//SC : O(V+E)
