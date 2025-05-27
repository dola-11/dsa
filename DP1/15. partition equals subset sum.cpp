// Memoization

class Solution {
public:
    bool subsetHelp(int index, int target, vector<int> & nums, vector<vector<int>> &dp)
    {
        if (target == 0) return true;
        if (index == 0) return (nums[0] == target);

        if (dp[index][target] != -1) return dp[index][target];

        bool notTake = subsetHelp(index-1,target,nums,dp);
        bool take = false;

        if (target >= nums[index])
        {
            take = subsetHelp(index-1, target - nums[index], nums, dp);
        }

        return dp[index][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int totSum = 0;
        int target = 0;
        for (int i=0; i<n; i++)
        {
            totSum += nums[i];
        }

        if (totSum % 2 != 0) return false;
        else
        {
            target = totSum/2;
        }

        vector<vector<int>>dp(n, vector<int>(target+1,-1));
        return subsetHelp(n-1,target,nums,dp);
    }
};

//TC : O(N*target)
//SC : O(N*target) + O(N)

//Tabulation

class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base cases:
        for (int i = 0; i < n; i++) 
            dp[i][0] = true;  // sum 0 is always possible with empty subset

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for (int index = 1; index < n; index++) 
        {
            for (int currTarget = 1; currTarget <= target; currTarget++) 
            {
                bool notTake = dp[index - 1][currTarget];
                bool take = false;
                if (nums[index] <= currTarget) 
                {
                    take = dp[index - 1][currTarget - nums[index]];
                }
                dp[index][currTarget] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};

//TC : O(N*target)
//SC : O(N*target)

//Space Optimization
class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<bool>prev(target+1,0), curr(target+1,0);

        prev[0] = curr[0] = true;
        prev[nums[0]] =true;

        for (int index = 1; index < n; index++) 
        {
            for (int currTarget = 1; currTarget <= target; currTarget++) 
            {
                bool notTake = prev[currTarget];
                bool take = false;
                if (nums[index] <= currTarget) 
                {
                    take = prev[currTarget - nums[index]];
                }
                curr[currTarget] = take || notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
};
//TC : O(N*target)
//SC : O(target)
