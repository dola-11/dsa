//Recursive

//Space and time are exponential, way greater than O(2^n) and O(n)
class Solution {
public:
    int combinationCoins(int index, int target, vector<int> &coins)
    {
        if (index == 0)
        {
            return (target % coins[0] == 0) ? 1 : 0;
        }
        int take = 0;
        int notTake = combinationCoins(index-1,target,coins);
        if (coins[index]<=target)
        {
            take = combinationCoins(index,target-coins[index],coins);
        }
        return take + notTake;
    }
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        return combinationCoins(n-1,amount,coins);
    }
};

//Memoization
class Solution {
public:
    int combinationCoins(int index, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            return (target % coins[0] == 0) ? 1 : 0;
        }
        if (dp[index][target] != -1) return dp[index][target];

        int take = 0;
        int notTake = combinationCoins(index-1,target,coins,dp);
        if (coins[index]<=target)
        {
            take = combinationCoins(index,target-coins[index],coins,dp);
        }
        return dp[index][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return combinationCoins(n-1,amount,coins,dp);
    }
};

//TC : O(N × amount)
//SC : O(N × amount + N)

//Tabulation
//have to use unsigned int to prevent overflow?
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        const int MOD = 1e11 + 7;
        int n = coins.size();
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(amount + 1, 0));

        for (int target=0; target <= amount; target++)
        {
            dp[0][target] = (target % coins[0] == 0);
        }

        for (int i=1; i<n; i++)
        {
            for(int target = 0; target <=amount; target++)
            {
                uint64_t notTake = dp[i - 1][target];
                uint64_t  take = 0;
                
                if (coins[i]<=target)
                {
                    take = dp[i][target-coins[i]];
                }
                dp[i][target] = (take + notTake) % MOD;
            }
        }
        return (int)dp[n-1][amount];
    }
};

//TC : O(N × amount)
//SC : O(N × amount)

/*
Unsigned integers only represent non-negative values
int (signed) range:
-2,147,483,648 to 2,147,483,647

unsigned int range:
0 to 4,294,967,295

So, if you're counting something that can never be negative (like combinations, ways to make change, sizes, indexes), unsigned gives you a larger safe range.
*/

//Space optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<uint64_t>prev(amount+1,0);
        vector<uint64_t>curr(amount+1,0);

        for (int target=0; target <= amount; target++)
        {
            prev[target] = (target % coins[0] == 0);
        }

        for (int i=1; i<n; i++)
        {
            for(int target = 0; target <=amount; target++)
            {
                uint64_t notTake = prev[target];
                uint64_t take = 0;
                
                if (coins[i]<=target)
                {
                    take = curr[target-coins[i]];
                }
                curr[target] = (take + notTake);
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};

//TC : O(N × amount)
//SC : O( amount)

//1d
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<uint64_t> dp(amount + 1, 0);

        // Base case: 1 way to make 0 amount
        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int target = coins[i]; target <= amount; target++)
            {
                dp[target] += dp[target - coins[i]];
            }
        }

        return (int)dp[amount];
    }
};
