//Recursive
//only for positive

//If arr[0] = 30, target = 20, then dp[0][30] causes:
//Runtime Error / Segmentation Fault.

class Solution {
  public:
    int countFunc(vector<int> & arr, int target, int index)
    {
        if (target == 0) return 1;
        if (index == 0) return arr[0] == target;
        
        int notTake = countFunc(arr,target,index-1);
        int take = 0;
        if (arr[index]<=target)
        {
            take = countFunc(arr, target-arr[index], index-1);
        }
        return take + notTake;
    }
    int perfectSum(vector<int>& arr, int target) 
    {
        int n = arr.size();
        return countFunc(arr,target,n-1);
    }
};

//SC : O(n)
//TC : O(2ⁿ)

//Memoization
//for non negative 
class Solution {
  public:
    int countFunc(vector<int> & arr, int target, int index, vector<vector<int>> &dp)
    {
        if (index == 0) 
        {
            if (target == 0 && arr[0] == 0) return 2; // include and exclude
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        
        if (dp[index][target] != -1) return dp[index][target];
        
        int notTake = countFunc(arr,target,index-1,dp);
        int take = 0;
        if (arr[index]<=target)
        {
            take = countFunc(arr, target-arr[index], index-1,dp);
        }
        return dp[index][target] = take + notTake;
    }
    
    int perfectSum(vector<int>& arr, int target) 
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return countFunc(arr,target,n-1,dp);
    }
};

//TC : 	O(n * target)
//SC : 	O(n * target) + O(n)

//Tabulation
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) 
    {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        //Base cases
        if (arr[0] == 0)
        {
            dp[0][0] = 2;//take or not take 0;  // {} and {0}
        }
        else
        {
            dp[0][0] = 1; // dont take, // only one way: don't pick anything — the empty set.
            if (arr[0] <= target)
            {
                dp[0][arr[0]] = 1; //take
            }
        }
        
        for (int i=1; i<n; i++)
        {
            for (int t=0; t<=target; t++)
            {
                int notTake = dp[i-1][t];
                int take = 0;
                if (arr[i] <= t)
                {
                    take = dp[i-1][t-arr[i]];
                }
                dp[i][t] = take + notTake;
            }
        }
        return dp[n-1][target];
    }
};

//SC : O(n × target)
//TC : O(n × target)

//Space Optimization
class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) 
    {
        // code here
        int n = arr.size();
        vector<int>prev(target+1,0);
        
        //Base cases
        if (arr[0] == 0)
        {
            prev[0] = 2;//take or not take 0;  // {} and {0}
        }
        else
        {
            prev[0] = 1; // dont take, // only one way: don't pick anything — the empty set.
            if (arr[0] <= target)
            {
                prev[arr[0]] = 1; //take
            }
        }
        
        for (int i=1; i<n; i++)
        {
            vector<int> curr(target + 1, 0);
            for (int t=0; t<=target; t++)
            {
                int notTake = prev[t];
                int take = 0;
                if (arr[i] <= t)
                {
                    take = prev[t-arr[i]];
                }
                curr[t] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};

//SC : O(target)
//TC : O(n × target)
