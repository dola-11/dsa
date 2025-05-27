class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        //structure is diff, coordinates.
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;

        dist[0][0] = 0;

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            int effort = node.first;
            int row = node.second.first;
            int column = node.second.second;

            if (row == n-1 && column == m-1) return effort;

            for (auto [dx,dy]: directions)
            {
                int newrow = row + dx;
                int newcol = column + dy;

                if (newrow >= 0 && newcol >=0 && newrow < n && newcol < m)
                {
                    int difference = abs(heights[newrow][newcol] - heights[row][column]);
                    int maxEffort = max (difference,effort);

                    if (maxEffort < dist[newrow][newcol])
                    {
                        dist[newrow][newcol] = maxEffort;
                        pq.push({dist[newrow][newcol],{newrow,newcol}});
                    }
                }
            }
        }
        return -1;
    }
};

//TC : O(n * m * log(n * m)) //E log(V)
//SC : O(n * m) 
