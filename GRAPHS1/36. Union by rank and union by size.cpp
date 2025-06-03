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



🧠 Core Idea
A Disjoint Set Union (DSU) or Union-Find data structure is used to manage a collection of non-overlapping sets.
It supports two main operations efficiently:

Find: Determine which set a particular element belongs to.
Union: Merge two sets into one.
    
The sets are disjoint — meaning, an element can belong to only one set at a time.



⚙️ Why is this useful?
Many problems require you to:
Track connectivity
Group elements together
Check if two elements belong to the same group
Dynamically merge sets while maintaining performance


| Application                               | What DSU Helps With                                                           |
| ----------------------------------------- | ----------------------------------------------------------------------------- |
| **Kruskal's Algorithm (MST)**             | Efficiently check if two vertices are in the same component (to avoid cycles) |
| **Connected Components in Graphs**        | Dynamically track which nodes are connected                                   |
| **Cycle Detection in Undirected Graphs**  | Detect if adding an edge would form a cycle                                   |
| **Network Connectivity**                  | Find if two users/computers are in the same subnet                            |
| **Image Processing (Regions)**            | Merge adjacent pixels into larger regions                                     |
| **Social Network Merging**                | Handle "friend circles" or merging user groups                                |
| **Dynamic Equivalence Problems**          | Maintain and query equivalence classes                                        |
| **Percolation theory (Physics models)**   | Model how liquid flows through connected regions                              |
| **Union-Find on Sets of People, Objects** | Grouping people with common properties dynamically                            |


