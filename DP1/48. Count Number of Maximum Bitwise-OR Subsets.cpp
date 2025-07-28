//Recursive approach

class Solution {
public:
    int subsetCount(vector<int>&nums, int index, int currOR, int maxOR)
    {
        if (index == nums.size())
        {
            return (currOR == maxOR) ? 1 : 0;
        }

        int noTake = subsetCount(nums, index+1, currOR, maxOR);
        int Take = subsetCount(nums, index+1, currOR | nums[index], maxOR);

        return noTake + Take;
    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n = nums.size();
        int maxOR = 0;

        for (int i=0; i<n; i++)
        {
            maxOR |= nums[i];
        }

        return subsetCount(nums,0,0,maxOR);
    }
};


//TC : Time complexity: O(2^n)
//SC : O(n)

//Memoization
class Solution {
public:
    int subsetCount(vector<int>&nums, int index, int currOR, int maxOR, vector<vector<int>>&dp)
    {
        if (index == nums.size())
        {
            return (currOR == maxOR) ? 1 : 0;
        }

        if (dp[index][currOR] != -1)
        {
            return dp[index][currOR];
        }
        int noTake = subsetCount(nums, index+1, currOR, maxOR,dp);
        int Take = subsetCount(nums, index+1, currOR | nums[index], maxOR,dp);

        return dp[index][currOR] = noTake + Take;
    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n = nums.size();
        int maxOR = 0;

        for (int i=0; i<n; i++)
        {
            maxOR |= nums[i];
        }

        vector<vector<int>> dp(n, vector<int>(maxOR + 1, -1));
        return subsetCount(nums,0,0,maxOR,dp);
    }
};


//dp[0][0] = 3 ← total number of subsets with OR == 3 starting from index 0

//TC : O(n⋅maxOrValue)
//SC : O(n⋅maxOrValue)

//Since the nums length is really small, the most optimal here would be bit masking

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n = nums.size();
        int maxOR = 0;

        for (int i=0; i<n; i++)
        {
            maxOR = maxOR | nums[i];
        }

        int cnt = 0;
        int subsets = 1<<n;

        for (int mask = 0; mask < subsets; mask++)
        {
            int curr = 0;
            for (int i=0; i<n; i++)
            {
                if (mask & (1<<i))
                {
                    curr |= nums[i];
                } 
            }
            if (curr == maxOR) cnt++;
        }
        return cnt;
    }
};

//Time: O(n * 2^n)
//Space: O(1)

