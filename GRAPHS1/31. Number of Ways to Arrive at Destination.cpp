class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        //undirected graph
        vector<vector<pair<int,int>>> adj(n);
        for (auto road : roads)
        {
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        vector<long long >dist(n,LLONG_MAX);
        vector<int>ways(n,0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});         //{dist,node}
        
        int mod = (int)(1e9 + 7);
        
        while(!pq.empty())
        {
            auto element = pq.top();
            pq.pop();

            long long dis = element.first;
            long long node = element.second;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                long adjWeight = it.second;
                //this is the first arrival(of this short distance)
                if (dis + adjWeight < dist[adjNode])
                {
                    dist[adjNode] = dis + adjWeight;
                    pq.push({dis + adjWeight, adjNode});
                    ways[adjNode] = ways[node];     //since this is the first time
                }
                else if (dis + adjWeight == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) %mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

//TC:	O(E log N)
//SC: 	O(N + E)
