//Recursive

class Solution {
public:
    int func(int index, vector<int> & coins, int target)
    {
        //base case
        if (index == 0)
        {
            if (target % coins[0] == 0 ) return target/coins[0];
            else return 1e9;
        }

        int notPick = 0 + func(index-1, coins, target);
        int pick = INT_MAX;
        if (coins[index] <= target)
        {
            pick = 1 + func(index, coins, target - coins[index]);
        }
        return min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        int ans = func(n-1,coins,amount);
        return (ans >= 1e9) ? -1 : ans;  
    }
};

//exponential space and time complexity, very large , TC : O(2^target) , SC : O(target)

//Memoization

class Solution {
public:
    int func(int index, vector<int> & coins, int target, vector<vector<int>>&dp)
    {
        //base case
        if (index == 0)
        {
            if (target % coins[0] == 0 ) return target/coins[0];
            else return 1e9;
        }
        if (dp[index][target] != -1) return dp[index][target];

        int notPick = 0 + func(index-1, coins, target,dp);
        int pick = INT_MAX;
        if (coins[index] <= target)
        {
            pick = 1 + func(index, coins, target - coins[index],dp);
        }
        return dp[index][target] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = func(n-1,coins,amount,dp);
        return (ans >= 1e9) ? -1 : ans;  
    }
};

//TC : 	O(n × amount)
//SC = O(n × amount) (DP table) + O(amount) (stack)

//Tabulation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        //base case for tabulation
        for (int target = 0 ; target <= amount; target++)
        {
            if(target % coins[0] == 0) 
            {
                dp[0][target] = target/coins[0];
            }
            else 
            {
                dp[0][target] = 1e9;
            }
        }

        for (int index = 1; index<n; index++)
        {
            for (int target =0; target <=amount; target++)
            {
                int notTake = 0 + dp[index-1][target];
                int take = INT_MAX;
                if (coins[index] <= target)
                {
                    take = 1 + dp[index][target-coins[index]];
                }
                dp[index][target] = min(take,notTake);
            }
        }
        int ans = dp[n - 1][amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};

//Time: O(n × amount)
//Space: O(n × amount)

//Space Optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<int>prev(amount+1,0);
        vector<int>curr(amount+1,0);

        //base case for tabulation
        for (int target = 0 ; target <= amount; target++)
        {
            if(target % coins[0] == 0) 
            {
                prev[target] = target/coins[0];
            }
            else 
            {
                prev[target] = 1e9;
            }
        }

        for (int index = 1; index<n; index++)
        {
            for (int target =0; target <=amount; target++)
            {
                int notTake = 0 + prev[target];
                int take = INT_MAX;
                if (coins[index] <= target)
                {
                    take = 1 + curr[target-coins[index]];
                }
                curr[target] = min(take,notTake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};

//Time: O(n × amount)
//Space: O(2 × amount)
