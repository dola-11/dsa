class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) 
    {
        // code here
        int N = adj.size();
        vector<int>distance(N,1e9);
        distance[src] = 0;
        
        queue<int>q;
        q.push(src);
    
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for (auto it : adj[node])
            {
                if (distance[node] + 1 < distance[it])
                {
                    distance[it] = distance[node]+1;
                    q.push(it);
                }
            }
        }
        
        vector<int>answer(N,-1);
        for (int i=0; i<N; i++)
        {
            if (distance[i] != 1e9)
            {
                answer[i] = distance[i];
            }
        }
        return answer;
    }
};

//TC : O(V+E)
//SC : O(V) + O(V) + O(V) = O(V)
