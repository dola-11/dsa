//exactly same as file 18

//only the tabulation here, refer file 18.
class Solution {
public:
    int subsetCountHelper(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));

        if (nums[0] == 0)
        {
            dp[0][0] = 2; //take or not take 0;  // {} and {0}
        }
        else
        {
            dp[0][0] = 1; // dont take, // only one way: don't pick anything — the empty set.
            if (nums[0] <= target)
            {
                dp[0][nums[0]] = 1;
            }
        }

        for (int i=1; i<n; i++)
        {
            for (int t=0; t<=target; t++)
            {
                int notTake = dp[i-1][t];
                int take = 0;
                if (nums[i] <= t)
                {
                    take = dp[i-1][t-nums[i]];
                }
                dp[i][t] = take + notTake;
            }
        }
        return dp[n-1][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totalsum = 0;
        int n = nums.size();
        for (int i=0; i<n; i++)
        {
            totalsum += nums[i];
        }
        if(totalsum - target < 0 || (totalsum-target)%2) return 0;
        return subsetCountHelper((totalsum - target)/2, nums);
    }
};
