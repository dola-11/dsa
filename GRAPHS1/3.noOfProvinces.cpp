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

/**

Example 1:

isConnected = [[1,1,0],[1,1,0],[0,0,1]]

 CITY |0 1 2
------|------
     0|1 1 0 
     1|1 1 0
     2|0 0 1


Connections:
0 ► 1
1 ► 0
2 ► none


Example 2:

isConnected = [[1,0,0],[0,1,0],[0,0,1]]

 |0 1 2
-|------
0|1 0 0 
1|0 1 0
2|0 0 1


Connections:
0 ► none
1 ► none
2 ► none


Example 3: 

 |0 1 2 3
---------
0|1 1 0 0 
1|1 1 1 0
2|0 1 1 1
3|0 0 1 1


0 ► 1
1 ► 0 2
2 ► 1 3
3 ► 2

**/

// User function Template for C++
class DisjointSet{
    
  public:
    vector<int> rank, size, parent;
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for (int i=0; i<n+1; i++)
        {
            parent[i] = i;
        }
    }
    
    int findUparent(int node)
    {
        if (node == parent[node]) return node;
        else
        {
            return parent[node] = findUparent(parent[node]);
        }
    }
    
    void unionBySize(int u,int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u]>size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        // code here
        DisjointSet ds(V);
        for (int i=0; i<V; i++)
        {
            for (int j=0; j<V; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.unionBySize(i,j);
                }
            }
        }
        
        int cnt = 0;
        for (int i=0; i<V; i++)
        {
            if (ds.findUparent(i) == i) cnt++; //or ds.parent[i] == i
        }
        return cnt;
    }
};


//O(v^2) for both space and time maybe
