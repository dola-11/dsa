class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>distMatrix(m,vector<int>(n,0));
        vector<vector<int>>visited(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            distMatrix[row][col] = dist;

            vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto [dx,dy] : directions)
            {
                int nrow = row + dx;
                int ncol = col + dy;
                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && visited[nrow][ncol] == 0)
                {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});

                }
            }
        }
        return distMatrix;
    }
};

//SC : O(m*n)
//TC : O(m*n)
