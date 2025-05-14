//Recursion - TLE


class Solution {
public:
    int recursion(vector<int>& nums, int index)
    {
        if (index < 0) return 0;
        if (index == 0) return nums[0];

        int pick = nums[index] + recursion(nums, index-2);
        int notpick = 0 + recursion(nums,index-1);

        return max(pick, notpick);
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        return recursion(nums,n-1);
    }
};

//TC : O(2^n)
//SC : O(n)

//Memoization
class Solution {
public:
    int recursion(vector<int>& nums, int index, vector<int>& dp)
    {

        if (index < 0) return 0;
        if (index == 0) return nums[0];
        if (dp[index] != -1) return dp[index];

        int pick = nums[index] + recursion(nums, index-2,dp);
        int notpick = 0 + recursion(nums,index-1,dp);

        dp[index] = max(pick, notpick);
        
        return dp[index];
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n,-1);
        return recursion(nums,n-1,dp);
    }
};

//TC : O(n)
//SC : O(n) + O(n)

//Tabulation
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];

        vector<int>dp(n,0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i=2; i<n; i++)
        {
            int pick = nums[i] + dp[i-2];
            int notpick = 0 + dp[i-1];

            dp[i] = max(pick, notpick);
        }
        return dp[n-1];
    }
};

//TC : O(n)
//SC : O(n) 
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==0) return 0;
        if (n==1) return nums[0];


        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i=2; i<n; i++)
        {
            int pick = nums[i] + prev2;
            int notpick = 0 + prev1;

            int current = max(pick, notpick);

            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

//TC : O(n)
//SC : O(1) 
