//Method 1:

class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> & visited, vector<int> &pathVisited, stack<int> &st)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfsCheck(it, adj, visited, pathVisited, st)) return true;
            }
            else if (pathVisited[it])
            {
                return true;
            }
        }
        pathVisited[node] =0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>adj(numCourses);

        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<int>visited(numCourses,0);
        vector<int>pathVisited(numCourses,0);
        stack<int> st;

        for (int i=0; i<numCourses; i++)
        {
            if (!visited[i]) 
            {
                if (dfsCheck(i, adj, visited, pathVisited, st)) 
                {
                    return {};
                }
            }
        }

        vector<int>result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

// TC : O(E) + O(V+E) + O(V) = O(V+E)
// SC : O(E) + O(V+V) + O(V) + O(V) + O(V) + O(V) = O(V+E)

//METHOD 2:
class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> & state, stack<int> &st)
    {
        state[node] = 1;

        for (auto it : adj[node])
        {
            if (state[it] == 0)
            {
                if (dfsCheck(it, adj, state, st)) return true;
            }
            else if (state[it] == 1)
            {
                return true;
            }
        }
        state[node] = 2;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>adj(numCourses);

        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<int>state(numCourses,0);
        stack<int> st;

        for (int i=0; i<numCourses; i++)
        {
            if (state[i] == 0) 
            {
                if (dfsCheck(i, adj, state, st)) 
                {
                    return {};
                }
            }
        }

        vector<int>result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};

//TC : O(E) + O(V) + O(V) = O(V+E)
//SC : O(E) + O(V) + O(V) + O(V) = O(V+E)
