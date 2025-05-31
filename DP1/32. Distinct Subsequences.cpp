//Recursion

class Solution {
public:
    int countHelper(int i, int j,string s, string t)
    {
        if (j<0) return 1;
        if (i<0) return 0;

        if (s[i] == t[j])
        {
            return countHelper(i-1,j-1,s,t) + countHelper(i-1,j,s,t);
        }

        return countHelper(i-1,j,s,t);
    }
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        return countHelper(n-1,m-1,s,t);
    }
};

//TC : O(2^N* 2^M) very large, exponential
//SC : O(N+M)

//Memoization
class Solution {
public:
    int countHelper(int i, int j,string s, string t,vector<vector<int>> &dp)
    {
        if (j<0) return 1;
        if (i<0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j])
        {
            return dp[i][j] = countHelper(i-1,j-1,s,t,dp) + countHelper(i-1,j,s,t,dp);
        }

        return dp[i][j] = countHelper(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return countHelper(n-1,m-1,s,t,dp);
    }
};
//TC : O(N*M)
//SC : O(N*M) + O(N+M)

//Memoization 1 based indexing
class Solution {
public:
    int countHelper(int i, int j,string s, string t,vector<vector<int>> &dp)
    {
        if (j==0) return 1;
        if (i==0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i-1] == t[j-1])
        {
            return dp[i][j] = countHelper(i-1,j-1,s,t,dp) + countHelper(i-1,j,s,t,dp);
        }

        return dp[i][j] = countHelper(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return countHelper(n,m,s,t,dp);
    }
};

//Tabulation
//int gives overflow

class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));

        for (int i=0; i<=n; i++) dp[i][0] = 1;

        for (int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if (s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};

//Space optimization possible
class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        vector<double>prev(m+1,0);
        vector<double>curr(m+1,0);

        prev[0] = curr[0] = 1;

        for (int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if (s[i-1] == t[j-1])
                {
                    curr[j] = prev[j-1] + prev[j];
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return (int)prev[m];
    }
};

//TC : O(N*M)
//SC : O(2*M) 

//Space optimization using 1D
class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        vector<double>prev(m+1,0);

        prev[0] = 1;

        for (int i=1; i<=n; i++)
        {
            for(int j=m; j>=1; j--)
            {
                if (s[i-1] == t[j-1])
                {
                    prev[j] = prev[j-1] + prev[j];
                }
            }
        }
        return (int)prev[m];
    }
};

//TC : O(N*M)
//SC : O(M) 
