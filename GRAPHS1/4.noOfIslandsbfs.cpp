class Solution {
public:
    void bfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        //grid[i][j] = '1';

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (auto [delrow,delcol] : directions)
            {
                int nrow = row + delrow;
                int ncol = col + delcol;

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1')
                {
                    grid[nrow][ncol] = '0';
                    q.push({nrow,ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int numOfIslands = 0;

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] == '1')
                {
                    numOfIslands ++;
                    bfs(grid,i,j);
                }
            }
        }
        return numOfIslands;
    }
};
