//Memoization

class Solution {
  public:
    int countFunc(int target, vector<int> &arr, int index, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        
        if (dp[index][target] != -1) return dp[index][target];
        
        int notTake = countFunc(target, arr, index -1,dp);
        int take = 0;
        if(arr[index] <= target)
        {
            take = countFunc(target - arr[index], arr, index-1,dp);
        }
        
        return dp[index][target] = take + notTake;
    }
    
    int countSubsetshelper(int target, vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return countFunc(target, arr, n-1,dp);
    }
    int countPartitions(vector<int>& arr, int d) 
    {
        // Code here
        int totalSum = 0;
        int n = arr.size();
        for (int i=0; i<n; i++)
        {
            totalSum += arr[i];
        }
        if (totalSum - d < 0 || (totalSum - d)%2) return 0;
        return countSubsetshelper((totalSum-d)/2, arr);
    }
};

//SC : O(n * target)
//TC : O(n * target) + O(n)

//Tabulation
class Solution {
  public:
    
    int countSubsetshelper(int target, vector<int> &arr)
    {
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
    int countPartitions(vector<int>& arr, int d) 
    {
        // Code here
        int totalSum = 0;
        int n = arr.size();
        for (int i=0; i<n; i++)
        {
            totalSum += arr[i];
        }
        if (totalSum - d < 0 || (totalSum - d)%2) return false;
        return countSubsetshelper((totalSum-d)/2, arr);
    }
};

//SC : O(n * target)
//TC : O(n * target)

//Space Optimization
class Solution {
  public:
    
    int countSubsetshelper(int target, vector<int> &arr)
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
    int countPartitions(vector<int>& arr, int d) 
    {
        // Code here
        int totalSum = 0;
        int n = arr.size();
        for (int i=0; i<n; i++)
        {
            totalSum += arr[i];
        }
        if (totalSum - d < 0 || (totalSum - d)%2) return false;
        return countSubsetshelper((totalSum-d)/2, arr);
    }
};

//SC : O(target)
//TC : O(n × target)
