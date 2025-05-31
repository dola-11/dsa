class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>> adj(n+1);      //1 based indexing of the nodes
        for (auto &edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,k});             //time, node

        vector<int>dist(n+1,1e9);
        dist[k] = 0;

        while(!pq.empty())
        {
            auto [time,node] = pq.top();
            pq.pop();

            for (auto &it : adj[node])
            {
                int neighbour = it.first;
                int weight = it.second;

                if (time + weight < dist[neighbour])
                {
                    dist[neighbour] = time + weight;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }

        //minimum time required for all nodes to recieve the signal, max time in the distance array
        int maxTime = 0;
        for (int i=1; i<=n; i++)
        {
            if (dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]); 
        }
        return maxTime;
    }
};

//SC : O(n + m)
//TC : O(m log n)
