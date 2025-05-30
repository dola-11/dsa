//Recursive

class Solution {
  public:
    int maxPrice(int index, int N, vector<int>&price)
    {
        if (index == 0) return N*price[0];
        
        int notTake = 0 + maxPrice(index-1,N,price);
        int take = INT_MIN;
        int rodlength = index+1;
        if (rodlength <= N)
        {
            take = price[index] + maxPrice(index, N - rodlength, price);
        }
        return max(take, notTake);
    }
    
    int cutRod(vector<int> &price) 
    {
        // code here
        int n = price.size();
        return maxPrice(n-1, n, price);
    }
};

//SC : O(n)
//TC : O(2^n)

//Memoization

class Solution {
  public:
    int maxPrice(int index, int N, vector<int>&price, vector<vector<int>>& dp)
    {
        if (index == 0) return N*price[0];
        
        if (dp[index][N] != -1) return dp[index][N];
        
        int notTake = 0 + maxPrice(index-1,N,price,dp);
        int take = INT_MIN;
        int rodlength = index+1;
        if (rodlength <= N)
        {
            take = price[index] + maxPrice(index, N - rodlength, price,dp);
        }
        return dp[index][N] = max(take, notTake);
    }
    
    int cutRod(vector<int> &price) 
    {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return maxPrice(n-1, n, price,dp);
    }
};

//TC : O(n^2)
//SC : O(n^2 + n)

//Tabulation
class Solution {
  public:
    int cutRod(vector<int> &price) 
    {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int N=0; N<=n; N++)
        {
            dp[0][N] = N*price[0];
        }
        
        for (int index = 1; index <n; index++)
        {
            for (int N=0; N<=n; N++)
            {
                int notTake = 0 + dp[index-1][N];
                int take = INT_MIN;
                int rodlength = index+1;
                if (rodlength <= N)
                {
                    take = price[index] + dp[index][N - rodlength];
                }
                dp[index][N] = max(take, notTake);
            }
        }
        return dp[n-1][n];
    }
};

//TC : O(n^2)
//SC : O(n^2)

//1.Space optimization using 2 1D arrays
class Solution {
  public:
    int cutRod(vector<int> &price) 
    {
        // code here
        int n = price.size();
        vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        
        for (int N=0; N<=n; N++)
        {
            prev[N] = N*price[0];
        }
        
        for (int index = 1; index <n; index++)
        {
            for (int N=0; N<=n; N++)
            {
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodlength = index+1;
                if (rodlength <= N)
                {
                    take = price[index] + curr[N - rodlength];
                }
                curr[N] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[n];
    }
};

//TC : O(n^2)
//SC : O(n * 2)

//2.Space optimization using 1 1D array
class Solution {
  public:
    int cutRod(vector<int> &price) 
    {
        // code here
        int n = price.size();
        vector<int>prev(n+1,0);
        
        for (int N=0; N<=n; N++)
        {
            prev[N] = N*price[0];
        }
        
        for (int index = 1; index <n; index++)
        {
            for (int N=0; N<=n; N++)
            {
                int notTake = 0 + prev[N];
                int take = INT_MIN;
                int rodlength = index+1;
                if (rodlength <= N)
                {
                    take = price[index] + prev[N - rodlength];
                }
                prev[N] = max(take, notTake);
            }
        }
        return prev[n];
    }
};

//TC : O(n^2)
//SC : O(n)
