//edge list given as input

// User function Template for C++
class DisjointSet{
    vector<int>parent,rank,size;
public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
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
    int kruskalsMST(int V, vector<vector<int>> &edges) 
    {
        // code here
        //edges[i] = {u,v,wt}
        
        //sorting edges based on their weight
        sort(edges.begin(),edges.end(), [](const vector<int>&a, const vector<int>&b)
        {
            return a[2]<b[2];
        });
        
        DisjointSet ds(V);
        int mstWt = 0;
        
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if (ds.findUparent(u) != ds.findUparent(v))
            {
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }

//TC : O(ElogE) + Each comparison (on w = edge[2]) is constant time: O(1) = O(ElogE)
//SC : O(1) (auxiliary space)+O(E) (to store the input edge list) = O(E)

//if graph isn't in the form of adjacency list

#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // 1 - 2 wt = 5
        /// 1 - > (2, 5)
        // 2 -> (1, 5)

        // 5, 1, 2
        // 5, 2, 1
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};

