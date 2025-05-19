//Recursive code for logic:
class Solution {
public:
    int minPathSum(vector<vector<int>> & matrix, int i,int j)
    {
        int n = matrix.size();
        if (n==0) return 0;

        if (j<0 || j>=n) return 1e9;
        if (i==0) return matrix[i][j];

        int straight = matrix[i][j] + minPathSum(matrix,i-1,j);
        int leftdiag = matrix[i][j] + minPathSum(matrix,i-1,j-1);
        int rightdiag = matrix[i][j] + minPathSum(matrix,i-1,j+1);

        return min(straight,min(leftdiag,rightdiag));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        if (n==0) return 0;
        int ans = 1e9; 

        for (int j = 0; j < n; j++) 
        {
            ans = min(ans, minPathSum(matrix, n - 1, j));
        }
        return ans;
    }
};

//TC : O(3^n)
//SC : O(n)

//Memoization
class Solution {
public:
    int minPathSum(vector<vector<int>> & matrix, int i,int j, vector<vector<int>>&dp)
    {
        int n = matrix.size();
        if (n==0) return 0;

        if (j<0 || j>=n) return 1e9;
        if (i==0) return matrix[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int straight = matrix[i][j] + minPathSum(matrix,i-1,j,dp);
        int leftdiag = matrix[i][j] + minPathSum(matrix,i-1,j-1,dp);
        int rightdiag = matrix[i][j] + minPathSum(matrix,i-1,j+1,dp);

        return dp[i][j]  = min(straight,min(leftdiag,rightdiag));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        if (n==0) return 0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = 1e9;

        for (int j = 0; j < n; j++) 
        {
            ans = min(ans, minPathSum(matrix, n - 1, j,dp));
        }
        return ans;
    }
};

//TC : O(n^2)
//SC : O(n^2) + O(n)

//Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        if (n==0) return 0;

        vector<vector<int>>dp(n,vector<int>(n,0));
        
        //basee casee
        for (int j=0; j<n; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        for (int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int straight = matrix[i][j] + dp[i-1][j];
                int leftdiag = (j > 0) ? matrix[i][j] + dp[i - 1][j - 1] : 1e9;
                int rightdiag = (j < n - 1) ? matrix[i][j] + dp[i - 1][j + 1] : 1e9;

                dp[i][j] = min(straight,min(leftdiag,rightdiag));
            }
        }

        int ans = 1e9;
        for (int j = 0; j < n; j++) 
        {
            ans = min(ans, dp[n - 1][j]);
        }
        return ans;
    }
};

//TC : O(n^2)+ O(n)
//SC : O(n^2) 

//Space optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        if (n==0) return 0;

        vector<int>prev(n);
        vector<int>curr(n);
        
        //basee casee
        for (int j=0; j<n; j++)
        {
            prev[j] = matrix[0][j];
        }

        for (int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int straight = matrix[i][j] + prev[j];
                int leftdiag = (j > 0) ? matrix[i][j] + prev[j - 1] : 1e9;
                int rightdiag = (j < n - 1) ? matrix[i][j] + prev[j + 1] : 1e9;

                curr[j] = min(straight,min(leftdiag,rightdiag));
            }
            prev = curr;
        }

        int ans = 1e9;
        for (int j = 0; j < n; j++) 
        {
            ans = min(ans, prev[j]);
        }
        return ans;
    }
};

//TC : O(n^2)+ O(n)
//SC : O(n) 
