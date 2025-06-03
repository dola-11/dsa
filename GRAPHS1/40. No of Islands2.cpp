class DisjointSet{
public:
    vector<int>parent, size;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<n+1; i++)
        {
            parent[i] = i;
        }
    }

    int findUparent(int node)
    {
        if (parent[node] == node) return node;
        else
        {
            return parent[node] = findUparent(parent[node]);
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

class Solution{
public:

bool isValid(int adjrow, int adjcol, int n, int m)
{
    return (adjrow >= 0 && adjrow < n && adjcol >= 0 && adjcol <m);
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &A)
    {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        int cnt = 0;
        vector<int> ans;

        for (auto it : A)
        {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;

            vector<int> dr = {0,1,0,-1};
            vector<int> dc = {1,0,-1,0};

            for (int ind = 0; ind <4; ind++)
            {
                int nrow = row + dr[ind];
                int ncol = col + dc[ind];
                if (isValid(nrow,ncol,n,m))
                {
                    if(vis[nrow][ncol] == 1)
                    {
                        int nodeNo = m*row + col;
                        int adjNodeNo = m*nrow + ncol;
                        if (ds.findUparent(nodeNo) != ds.findUparent(adjNodeNo))
                        {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }

            ans.push_back(cnt);
        }
        return ans;
    }
};

//TC: O(n*m + 4*k*α(n*m)) ≈ O(n*m + k)
//SC: O(n*m + k)
