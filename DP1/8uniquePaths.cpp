//First solution is combinatorics solution
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        int N = m + n - 2;
        int r = min(m - 1, n - 1); // Choose smaller for efficiency
        long long res = 1;

        for (int i = 1; i <= r; ++i) {
            res = res * (N - r + i) / i;
        }

        return (int)res;
    }
};

//TC : O(min(m,n))
//SC : O(1)

//DP section
//Memoization
class Solution {
public:
    int memoization(int i, int j, vector<vector<int>> &dp)
    {
        if (i==0 && j==0) return 1;
        if (i<0 || j<0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int up = memoization(i-1, j, dp);
        int left = memoization(i, j-1, dp);

        dp[i][j] = up + left;

        return dp[i][j];
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        int totalPaths = memoization(m-1,n-1,dp);
        return totalPaths;
    }
};

//TC : O(m*n)
//SC : O(m-1 + n-1) + O(m*n)

//Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m, vector<int>(n,0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (i==0 && j==0) dp[i][j] = 1;
                else
                {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
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
    int uniquePaths(int m, int n) 
    {
        vector<int>prev(n,0);   // stores values for previous row

        for(int i=0; i<m; i++)
        {
            vector<int>curr(n,0);   // current row
            for(int j=0; j<n; j++)
            {
                if (i==0 && j==0) curr[j] = 1;
                else
                {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
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
