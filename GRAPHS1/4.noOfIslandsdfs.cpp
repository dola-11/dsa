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
