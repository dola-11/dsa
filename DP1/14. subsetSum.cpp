//Memoization

class Solution {
  public:
    bool subsetHelp(int index, int sum, vector<int> &arr,vector<vector<int>>& dp)
    {
        if (sum == 0) return true;
        if (index == 0) return (arr[0] == sum);
        
        if (dp[index][sum]!= -1) return dp[index][sum];
        
        bool notTake = subsetHelp(index-1, sum, arr, dp);
        bool take = false;
        if (sum >= arr[index])
        {
            take = subsetHelp(index-1, sum-arr[index],arr,dp);
        }
        
        return dp[index][sum] = notTake || take;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        return subsetHelp(n-1,sum,arr,dp);
    }
};
//TC : O(N*target)
//SC : O(N*target) + O(N)

//Tabulation
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        
        for (int i = 0; i < n; i++) 
        {
            dp[i][0] = true;
        }
        
        if (arr[0] <= sum)
        {
            dp[0][arr[0]] = true;
        }

        for (int index = 1; index <n; index ++)
        {
            for (int target = 0; target<=sum; target++)
            {
                bool notTake = dp[index-1][target];
                bool take = false;
                if (target >= arr[index])
                take = dp[index - 1][target - arr[index]];
                dp[index][target] = take || notTake;
            }
        }
        return dp[n-1][sum];
    }
};
//TC : O(N*target)
//SC : O(N*target)

//Space Optimization
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) 
    {
        int n = arr.size();
        vector<bool>prev(sum+1,0), curr(sum+1,0);
        
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;

        for (int index = 1; index <n; index ++)
        {
            for (int target = 0; target<=sum; target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if (target >= arr[index])
                take = prev[target - arr[index]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};
//TC : O(N*target)
//SC : O(target)
