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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        DisjointSet ds(n);
        int cntExtras = 0;
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];

            if (ds.findUparent(u) == ds.findUparent(v))
            {
                cntExtras ++;
            }
            else
            {
                ds.unionBySize(u,v);
            }
        }

        int cntC = 0;
        for (int i=0; i<n; i++)
        {
            if(ds.findUparent(i) == i) cntC++;
        }

        int ans = cntC-1;

        if (cntExtras >= ans) return ans;
        return -1;
    }
};

//TC : O(N+E)
//SC : O(N)
