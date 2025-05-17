//Memoization

class Solution {
public:
    int memoization(int i,int j, vector<vector<int>>& dp, vector<vector<int>> & obstacleGrid)
    {
        if (i>=0 && j>=0 && obstacleGrid[i][j] == 1) return 0;
        if (i<0 || j<0) return 0;
        if (i==0 && j==0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int up = memoization(i-1,j,dp,obstacleGrid);
        int left = memoization(i,j-1,dp,obstacleGrid);

        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        int totalPaths = memoization(m-1,n-1,dp, obstacleGrid);
        return totalPaths;
    }
};

//TC : O(m*n)
//SC : O(m*n) + O(m*n)

//Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;

                else if (i==0 && j==0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int up = (i>0) ? dp[i-1][j] : 0;
                    int left = (j>0) ? dp[i][j-1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};

//TC : O(m*n)
//SC : O(m*n)

//Space optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int>prev(n,0);

        for (int i=0; i<m; i++)
        {
            vector<int>curr(n,0);
            for (int j=0; j<n; j++)
            {
                if (obstacleGrid[i][j] == 1) curr[j] = 0;

                else if (i==0 && j==0)
                {
                    curr[j] = 1;
                }
                else
                {
                    int up = (i>0) ? prev[j] : 0;
                    int left = (j>0) ? curr[j-1] : 0;
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }
};

//TC : O(m*n)
//SC : O(n)
