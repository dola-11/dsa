//Memoization

class Solution {
public:
    int memoization(int i, int j, vector<vector<int>>& grid, vector<vector<int>> & dp)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i==0 && j==0) return grid[0][0];
        if (i<0 || j<0) return 1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = grid[i][j] + memoization(i-1,j,grid,dp);
        int left = grid[i][j] + memoization(i,j-1,grid,dp);

        dp[i][j] = min(up,left);

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        int minSum = memoization(m-1,n-1,grid,dp);
        return minSum;
    }
};

//TC : O(m*n)
//SC : O(m*n) + O(m*n)

//Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (i==0 && j==0) dp[i][j] = grid[0][0];
                else
                {
                    int up = (i>0) ? grid[i][j] + dp[i-1][j] : 1e9;
                    int left = (j>0) ? grid[i][j] + dp[i][j-1] : 1e9;

                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//TC : O(m*n)
//SC : O(m*n)

// Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>prev(n,0);

        for(int i=0; i<m; i++)
        {
            vector<int>curr(n,0);
            for(int j=0; j<n; j++)
            {
                if (i==0 && j==0) curr[j] = grid[0][0];
                else
                {
                    int up = (i>0) ? grid[i][j] + prev[j] : 1e9;
                    int left = (j>0) ? grid[i][j] + curr[j-1] : 1e9;

                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

//TC : O(m*n)
//SC : O(n)
