class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]!= '1') return;
        grid[i][j] = 0;         //i dont need a separate visited array, can just convert the land into water

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);

    }
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int noOfIslands = 0;

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]== '1')
                {
                    noOfIslands++;
                    dfs(grid,i,j);
                }
            }
        }
        return noOfIslands;
    }
};


//using visited array
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0' || visited[row][col] == 1) return;

        visited[row][col] = 1;

        dfs(row+1,col,visited,grid);
        dfs(row,col+1,visited,grid);
        dfs(row-1,col,visited,grid);
        dfs(row,col-1,visited,grid);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int noOfIslands =0;

        vector<vector<int>>visited(m,vector<int>(n,0));

        for (int i=0; i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == 0)
                {
                    noOfIslands++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return noOfIslands;
    }
};


//TC : O(m × n)
//SC : O(m × n)
