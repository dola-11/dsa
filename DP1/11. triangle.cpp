//Memeoizatio

class Solution {
public:
    int memoization(int i,int j, vector<vector<int>> & triangle, vector<vector<int>> &dp)
    {
        int m = triangle.size();

        if (i == m - 1) return triangle[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + memoization(i+1,j,triangle,dp);
        int diag = triangle[i][j] + memoization(i+1,j+1,triangle,dp);

        return dp[i][j] = min (down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
      
        vector<vector<int>> dp(m, vector<int>(m, -1));
        int minCost = memoization(0,0,triangle,dp);

        return minCost;
    }
};

//TC : O(m^2)
//SC : O(m^2) + O(m)

//Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            dp[m-1][j] = triangle[m-1][j];
        }

        for (int i = m-2; i>=0; i--)
        {
            for(int j = i; j>=0; j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min (down, diag);
            }
        }

        return dp[0][0];
    }
};
//TC : O(m^2)
//SC : O(m^2) 

//Space Optimization

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();
        vector<int>front(m);

        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            front[j] = triangle[m-1][j];
        }

        for (int i = m-2; i>=0; i--)
        {
            vector<int>curr(m);
            for(int j = i; j>=0; j--)
            {
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j+1];

                curr[j] = min (down, diag);
            }
            front = curr;
        }

        return front[0];
    }
};

//TC : O(m^2)
//SC : O(m) 
