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
    int removeStones(vector<vector<int>>& stones) 
    {
        int maxRow = 0;
        int maxCol = 0;

        for (auto it:stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol +1);
        
        unordered_map<int,int> stoneNodes;

        for (auto it:stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow+1;
            ds.unionBySize(nodeRow, nodeCol);
            
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it:stoneNodes)
        {
            if(ds.findUparent(it.first) == it.first)
            cnt++;
        }
        return stones.size() - cnt;
    }
};

//TC: O(n * α(N)) ≈ O(n)
//SC: O(R + C + n)
