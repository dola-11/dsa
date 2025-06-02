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


//using visited array

class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>&grid, vector<vector<int>> & visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        visited[row][col] = 1;

        vector<pair<int,int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (auto [delrow,delcol] : directions)
            {
                int nrow = i + delrow;
                int ncol = j + delcol;
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1' && !visited[nrow][ncol])
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        int noOfIslands = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    bfs(i,j,grid,visited);
                    noOfIslands++;
                }
            }
        }
        return noOfIslands;
    }
};
