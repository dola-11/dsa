// Using priority queue

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) 
    {
        // Code here
        vector<vector<pair<int,int>>>adjList(V);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distance(V,1e9);
        
        distance[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            //it is a pair<int,int> — access via .first and .second
            for (auto it : adjList[node])
            {
                int edgeWeight = it.second;
                int currNode = it.first;
                
                if (dis + edgeWeight < distance[currNode])
                {
                    distance[currNode] = dis + edgeWeight;
                    pq.push({distance[currNode], currNode});
                }
            }
        }
        return distance;
    }
};

//TC : O(E log V)
//TC : O(V + E)

//Using set

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) 
    {
        // Code here
        vector<vector<pair<int,int>>>adjList(V);
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjList[u].push_back({v,wt});
        }
        
        set<pair<int,int>> st;
        vector<int>distance(V,1e9);
        
        distance[src] = 0;
        st.insert({0, src});
        
        while(!st.empty())
        {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(st.begin());
            
            for (auto adjacentNode : adjList[node])
            {
                int edgeWeight = adjacentNode.second;
                int currNode = adjacentNode.first;
                
                if (edgeWeight + dis < distance[currNode])
                {
                    if (distance[currNode] != 1e9)
                    {
                        st.erase({distance[currNode], currNode});
                    }
                    distance[currNode] = edgeWeight + dis;
                    st.insert({distance[currNode],currNode});
                }
            }
        }
        return distance;
    }
};

//TC : O(E log V)
//TC : O(V + E)

//A set gives you the ability to update distances easily by erasing old entries.
//In priority_queue, you cannot erase a specific element, so duplicates remain.
