//Recursive Implementation

class Solution {
  public:
    int func(int index, int W, vector<int> &val, vector<int> &wt)
    {
        if (index == 0)
        {
            if (wt[0] <= W) return val[0];
            else
            {
                return 0;
            }
        }
        
        int notTake = 0 + func(index-1,W,val,wt);
        int take = INT_MIN;
        
        if (wt[index]<=W)
        {
            take = val[index] + func(index-1,W-wt[index],val,wt);
        }
        
        return max(take,notTake);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int noOfItems = val.size();
        return func( noOfItems-1,W,val, wt);
    }
};

//TC : O(2ⁿ)
//SC : 	O(n)

//Memoized
class Solution {
  public:
    int func(int index, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (wt[0] <= W) return val[0];
            else
            {
                return 0;
            }
        }
        
        if (dp[index][W] != -1) return dp[index][W];
        
        int notTake = 0 + func(index-1,W,val,wt,dp);
        int take = INT_MIN;
        
        if (wt[index]<=W)
        {
            take = val[index] + func(index-1,W-wt[index],val,wt,dp);
        }
        
        return dp[index][W] = max(take,notTake);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int noOfItems = val.size();
        vector<vector<int>>dp(noOfItems,vector<int>(W+1,-1));
        return func( noOfItems-1,W,val, wt,dp);
    }
};

//SC : O(n×W) + O(n)
​//TC : 	O(n × W)

//Tabulation
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        int n = val.size(); 
        vector<vector<int>>dp(n, vector<int>(W+1,0));
        
        for (int i = wt[0]; i<=W; i++)
        {
            dp[0][i] = val[0];
        }
        
        for (int index=1; index<n; index++)
        {
            for(int weight = 0; weight <= W; weight++)
            {
                int notTake = 0 + dp[index-1][weight];
                int take = INT_MIN;
                if(wt[index] <= weight)
                {
                    take = val[index] + dp[index-1][weight - wt[index]];
                }
                dp[index][weight] = max(take,notTake);
            }
        }
        return dp[n-1][W];
    }
};

//TC : O(n*W)
//SC : O(n*W)

//Space Optimization 1

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        int n = val.size(); 
        vector<int>prev(W+1,0);
        vector<int>curr(W+1,0);
        
        for (int i = wt[0]; i<=W; i++)
        {
            prev[i] = val[0];
        }
        
        for (int index=1; index<n; index++)
        {
            for(int weight = 0; weight <= W; weight++)
            {
                int notTake = 0 + prev[weight];
                int take = INT_MIN;
                if(wt[index] <= weight)
                {
                    take = val[index] + prev[weight - wt[index]];
                }
                curr[weight] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};

//TC : O(n × W)
//SC : O(2 × W) = O(W)

//Space optimization using only 1 array
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        int n = val.size(); 
        vector<int>prev(W+1,0);
        
        for (int i = wt[0]; i<=W; i++)
        {
            prev[i] = val[0];
        }
        
        for (int index=1; index<n; index++)
        {
            for(int weight = W; weight >= 0; weight--)
            {
                int notTake = 0 + prev[weight];
                int take = INT_MIN;
                if(wt[index] <= weight)
                {
                    take = val[index] + prev[weight - wt[index]];
                }
                prev[weight] = max(take,notTake);
            }
        }
        return prev[W];
    }
};

//TC : O(n × W)
//SC : O(W)

//To make this work in 1D, you must loop weights backwards (from W to 0) to ensure that when computing dp[weight], the value dp[weight - wt[i]] still represents the result from the previous item.
//If you loop forward (weight = 0 to W), the dp[weight - wt[i]] would be already updated in the same iteration, which simulates taking the item more than once, violating the 0/1 constraint.

