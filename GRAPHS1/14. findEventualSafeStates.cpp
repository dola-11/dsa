//Using dfs and the concept of detecting cycles in a directed graph

class Solution {
public:
    bool dfs(int node, vector<int> &visited, vector<int> &pathVisited, vector<vector<int>> &graph, vector<int>&check)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;

        for (auto it : graph[node])
        {
            if (!visited[it])
            {
                if (dfs(it,visited,pathVisited,graph,check)==true)
                {
                    check[it] = 0;
                    return true;
                }
            }
            else if (visited[it] == 1 && pathVisited[it] == 1)
            {
                check[it] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();

        vector<int> visited(n,0);
        vector<int> pathVisited(n,0);
        vector<int> check(n,0);

        vector<int>safeNodes;

        for (int i=0; i<n; i++)
        {
            if (!visited[i])
            {
                dfs(i,visited,pathVisited,graph,check);
            }         
        }

        for (int i=0; i<n; i++)
        {
            if (check[i] == 1)
            safeNodes.push_back(i);
        }

        return safeNodes;
    }
};

//if we use counter in visited array to decrease space complexity, the readability of the code goes down, so the above approach works better for interviews?

//gpt generate using one vector in place of three
class Solution {
public:
    bool dfs(int node, vector<int>& state, vector<vector<int>>& graph) {
        if (state[node] != 0) {
            return state[node] == 2; // return true if already known to be safe
        }

        state[node] = 1; // mark as visiting (on recursion stack)

        for (int neighbor : graph[node]) {
            if (state[neighbor] == 2) continue; // already known to be safe
            if (state[neighbor] == 1 || !dfs(neighbor, state, graph)) {
                return false; // found a cycle
            }
        }

        state[node] = 2; // mark as safe
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0); // 0 = unvisited, 1 = visiting, 2 = safe
        vector<int> safeNodes;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, state, graph)) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
