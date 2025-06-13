//Recursive

class Solution {
public:
    int recursion(int index, int buy, vector<int>&prices)
    {
        int profit = 0;
        int n = prices.size();
        if (index == n) return 0;
        if (buy == 1)
        {
            profit = max(-prices[index] + recursion(index+1,0,prices), 0 + recursion(index+1,1,prices));
        }
        else if (buy == 0)
        {
            profit = max(+prices[index] + recursion(index+1,1,prices), 0 + recursion(index+1,0,prices));
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int buy = 1;
        return recursion(0, buy, prices);
    }
};

//Time:O(2^n)
//Space: O(n)

//Memoization
class Solution {
public:
    int recursion(int index, int buy, vector<int>&prices, vector<vector<int>>&dp)
    {
        int profit = 0;
        int n = prices.size();
        if (index == n) return 0;
        if (dp[index][buy] != -1) return dp[index][buy];

        if (buy == 1)
        {
            profit = max(-prices[index] + recursion(index+1,0,prices,dp), 0 + recursion(index+1,1,prices,dp));
        }
        else if (buy == 0)
        {
            profit = max(+prices[index] + recursion(index+1,1,prices,dp), 0 + recursion(index+1,0,prices,dp));
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return recursion(0, 1, prices,dp);
    }
};

//TC : O(N * 2) 
//SC : O(N * 2) for DP table + O(N) recursion stack.

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,0));

        for (int index = n-1; index>=0; index--)
        {
            for (int buy =0; buy <=1; buy++)
            {
                if (buy == 1)
                {
                    dp[index][buy] = max(-prices[index] + dp[index+1][0], 0 + dp[index+1][1]);
                }
                else if (buy == 0)
                {
                    dp[index][buy] = max(+prices[index] + dp[index+1][1], 0 + dp[index+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
//TC : O(N * 2) 
//SC : O(N * 2)

//Space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>ahead(2,0);

        for (int index = n-1; index>=0; index--)
        {
            for (int buy =0; buy <=1; buy++)
            {
                if (buy == 1)
                {
                    curr[buy] = max(-prices[index] + ahead[0], 0 + ahead[1]);
                }
                else if (buy == 0)
                {
                    curr[buy] = max(+prices[index] + ahead[1], 0 +ahead[0]);
                }
            }
            ahead = curr;
        }
        return curr[1];
    }
};

//Time: O(N)
//Space: O(1) (since 2 * 2 arrays)

/*
Return curr[1] ✅
Why not curr[0]?
curr[0] would be the profit if you are not allowed to buy at index 0, i.e., you already hold stock at the very beginning, which is not possible at the start.
*/


//Space Optimization using 4 variables
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int currBuy = 0, currNotbuy = 0, aheadBuy = 0, aheadNotbuy = 0;

        for (int index = n-1; index>=0; index--)
        {
            
            currBuy = max(-prices[index] + aheadNotbuy, 0 + aheadBuy);
                
            currNotbuy = max(+prices[index] + aheadBuy, 0 + aheadNotbuy);

            aheadBuy = currBuy;
            aheadNotbuy = currNotbuy;  
        }

        return currBuy;
    }
};

//Time: O(N)
//Space: O(1) 
