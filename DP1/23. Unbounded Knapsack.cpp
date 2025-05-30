//Recursive:

class Solution {
  public:
    int func(int index, int W, vector<int> &val, vector<int> &wt)
    {
        if (index == 0)
        {
            return ((W/wt[0]) * val[0]);
        }
        
        int notTake = 0 + func(index-1,W,val,wt);
        int take = INT_MIN;
        
        if (wt[index]<=W)
        {
            take = val[index] + func(index,W-wt[index],val,wt);
        }
        
        return max(take,notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        // code here
        int noOfItems = val.size();
        return func( noOfItems-1,capacity,val, wt);
    }
};

//TC : O(2ⁿ * W) 
//SC : O(W)

//Memoization
class Solution {
  public:
    int func(int index, int W, vector<int> &val, vector<int> &wt,vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            return ((W/wt[0]) * val[0]);
        }
        
        if (dp[index][W] != -1) return dp[index][W];
        
        int notTake = 0 + func(index-1,W,val,wt,dp);
        int take = INT_MIN;
        
        if (wt[index]<=W)
        {
            take = val[index] + func(index,W-wt[index],val,wt,dp);
        }
        
        return dp[index][W] = max(take,notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        // code here
        int noOfItems = val.size();
        vector<vector<int>>dp(noOfItems,vector<int>(capacity+1,-1));
        return func( noOfItems-1,capacity,val, wt,dp);
    }
};

//TC : O(n × W)
//SC : O(n × W + n)

//Tabulation
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        // code here
        int n = val.size(); 
        vector<vector<int>>dp(n, vector<int>(capacity+1,0));
        
        for (int i = wt[0]; i<=capacity; i++)
        {
            dp[0][i] = (i/wt[0]) * val[0];
        }
        
        for (int index=1; index<n; index++)
        {
            for(int weight = 0; weight <= capacity; weight++)
            {
                int notTake = 0 + dp[index-1][weight];
                int take = INT_MIN;
                if(wt[index] <= weight)
                {
                    take = val[index] + dp[index][weight - wt[index]];
                }
                dp[index][weight] = max(take,notTake);
            }
        }
        return dp[n-1][capacity];
    }
};

//TC : O(n × W)
//SC : O(n × W)

//Space optimization using 2 1D array
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        // code here
        int n = val.size(); 
        vector<int>prev(capacity+1,0);
        vector<int>curr(capacity+1,0);
        
        for (int i = wt[0]; i<=capacity; i++)
        {
            prev[i] = (i/wt[0]) * val[0];
        }
        
        for (int index=1; index<n; index++)
        {
            for(int weight = 0; weight <= capacity; weight++)
            {
                int notTake = 0 + prev[weight];
                int take = INT_MIN;
                if(wt[index] <= weight)
                {
                    take = val[index] + curr[weight - wt[index]];
                }
                curr[weight] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[capacity];
    }
};

//TC : O(n × W)
//SC : O(2 × W)
//Space optimization using 1 1D array
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        // code here
        int n = val.size(); 
        vector<int>prev(capacity+1,0);

        
        for (int i = wt[0]; i<=capacity; i++)
        {
            prev[i] = (i/wt[0]) * val[0];
        }
        
        for (int index=1; index<n; index++)
        {
            for(int weight = 0; weight <= capacity; weight++)
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
        return prev[capacity];
    }
};

//TC : O(n × W)
//SC : O(W)
