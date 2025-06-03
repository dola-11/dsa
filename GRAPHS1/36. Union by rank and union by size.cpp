class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


//α(n) = Inverse Ackermann function → practically constant (≤ 5)
| Operation     | Time Complexity |
| ------------- | --------------- |
| `findUparent` | **O(α(n))**     |
| `unionByRank` | **O(α(n))**     |
| `unionBySize` | **O(α(n))**     |

| Component | Space Used |
| --------- | ---------- |
| `parent`  | O(n)       |
| `rank`    | O(n)       |
| `size`    | O(n)       |
| **Total** | **O(n)**   |

