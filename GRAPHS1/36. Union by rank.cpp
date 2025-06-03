#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, rank;
public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
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
    
    void unionByRank(int u,int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
             parent[ulp_v] = ulp_u;
             rank[ulp_u]++;
        }
    }
};


| Operation     | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| `findUparent` | O(α(n))         | O(n)             |
| `unionByRank` | O(α(n))         | O(n)             |
