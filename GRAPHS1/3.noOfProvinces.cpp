class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        visit[node] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[node][i] && !visit[i]) {
                dfs(i, isConnected, visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        //could hv changed the adjacency matrix to adjacency list
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                dfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};

//tried converting the matrix to list
class Solution {
public:
    void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visit)
    {
        visit[node] = true;

        for (auto it : adjList[node])
        {
            if(!visit[it])
            {
                dfs(it,adjList,visit);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<vector<int>>adjList(n);

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (isConnected[i][j] && i!=j)
                {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<bool>visit(n,false);
        int noOfComponents = 0;

        for(int i=0; i<n; i++)
        {
            if(!visit[i])
            {
                noOfComponents++;
                dfs(i,adjList,visit);
            }
        }
        return noOfComponents;
    }
};
