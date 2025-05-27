class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adjList(n + 1); // 1-based indexing
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        // Step 2: Initialize
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n + 1, 1e9);
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        distance[1] = 0;
        pq.push({0, 1});

        // Step 3: Dijkstra's algorithm
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adjList[node]) {
                int adjacentNode = it.first;
                int edgeWeight = it.second;
                if (dis + edgeWeight < distance[adjacentNode]) {
                    distance[adjacentNode] = dis + edgeWeight;
                    pq.push({distance[adjacentNode], adjacentNode});
                    parent[adjacentNode] = node;
                }
            }
        }

        // Step 4: If no path exists
        if (distance[n] == 1e9) return {-1};

        // Step 5: Reconstruct path
        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        // Step 6: Add total weight to front
        path.insert(path.begin(), distance[n]);

        return path;
    }
};

//SC : O(n + m) + O(n) + O(n) + O(n) + O(n) = O(n + m) 
//TC : O(m log n)
