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
    bool isValid(int adjrow, int adjcol, int n)
    {
        return (adjrow >= 0 && adjrow < n && adjcol >= 0 && adjcol <n);
    }

    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        DisjointSet ds(n*n);

        // Step 1: Union all adjacent 1's
        for(int row = 0; row<n; row++)
        {
            for (int col = 0; col<n; col++)
            {
                if (grid[row][col] == 0) continue;
                vector<int> dr = {0,1,0,-1};
                vector<int> dc = {1,0,-1,0};

                for (int index = 0; index<4; index++)
                {
                    int nrow = row + dr[index];
                    int ncol = col + dc[index];
                    if (isValid(nrow,ncol,n) && grid[nrow][ncol]==1)
                    {
                        int nodeNo = row*n + col;
                        int adjnodeNo = nrow*n + ncol;
                        ds.unionBySize(nodeNo, adjnodeNo);
                    }
                }
            }
        }

        // Step 2: Try changing each 0 to 1 and calculate island size
        int mx = 0;
        bool hasZero = false;

        for(int row = 0; row<n; row++)
        {
            for (int col = 0; col<n; col++)
            {
                if (grid[row][col] == 1) continue;
                hasZero = true;
                vector<int> dr = {0,1,0,-1};
                vector<int> dc = {1,0,-1,0};
                set<int>components;

                for (int index = 0; index<4; index++)
                {
                    int nrow = row + dr[index];
                    int ncol = col + dc[index];
                    if (isValid(nrow,ncol,n))
                    {
                        if(grid[nrow][ncol] == 1)
                        {
                            components.insert(ds.findUparent(nrow*n+ ncol));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components)
                {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx,sizeTotal+1);
            }
        }

        if (!hasZero) return n * n;
        return mx;
    }
};

| Step               | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| DSU initialization | O(n²)           | O(n²)            |
| Union adjacent 1s  | O(n²)           | O(n²)            |
| Flipping 0s        | O(n²)           | O(1) per flip    |
| **Total**          | **O(n²)**       | **O(n²)**        |

  
