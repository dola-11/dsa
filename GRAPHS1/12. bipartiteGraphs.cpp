//bfs

//check for connected components as well
class Solution {
public:
    bool check(int start, int v,vector<vector<int>>& graph, vector<int> &colour)
    {
        v = graph.size();

        queue<int> q;
        q.push(start);
        colour[start] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : graph[node])
            {
                if (colour[it] == -1)
                {
                    colour[it] = !colour[node];
                    q.push(it);
                }
                else if (colour[it] == colour[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v = graph.size();
        vector<int>colour(v,-1);

        for (int i=0; i<v; i++)
        {
            if (colour[i] == -1)
            {
                if (check(i,v,graph,colour) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

//dfs
class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& colour)
    {
        colour[node] = col;

        for (auto it : graph[node])
        {
            if (colour[it] == -1)
            {
                dfs(it,!col,graph,colour);
            }
            else if (colour[it] == col)
            {
                return false;
            }
        } 
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v = graph.size();
        vector<int>colour(v,-1);

        for (int i=0; i<v; i++)
        {
            if (colour[i] == -1)
            {
                if (dfs(i,0,graph,colour) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
