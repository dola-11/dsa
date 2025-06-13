//Recursion

class Solution {
public:
        int recursion(int index, int buy, int fee, vector<int>&prices)
        {
            int profit = 0;
            int n = prices.size();
            if (index == n) return 0;
            if (buy == 1)
            {
                profit = max(-prices[index] + recursion(index+1,0,fee,prices), 0 + recursion(index+1,1,fee,prices));
            }
            else if (buy == 0)
            {
                profit = max(+prices[index] - fee + recursion(index+1,1,fee,prices), 0 + recursion(index+1,0,fee,prices));
            }
            return profit;
        }

    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        return recursion(0, 1, fee, prices);
    }
};

//Time: O(2^n)
//Space: O(n)

//Memoization
class Solution {
public:
        int recursion(int index, int buy, int fee, vector<int>&prices, vector<vector<int>>&dp)
        {
            int profit = 0;
            int n = prices.size();
            if (index == n) return 0;
            if (dp[index][buy] != -1) return dp[index][buy];

            if (buy == 1)
            {
                profit = max(-prices[index] + recursion(index+1,0,fee,prices,dp), 0 + recursion(index+1,1,fee,prices,dp));
            }
            else if (buy == 0)
            {
                profit = max(+prices[index] - fee + recursion(index+1,1,fee,prices,dp), 0 + recursion(index+1,0,fee,prices,dp));
            }
            return dp[index][buy] = profit;
        }

    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return recursion(0, 1, fee, prices,dp);
    }
};

//Time: O(n)
//Space: O(n) (DP table) + O(n) (recursion stack)

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
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
                    dp[index][buy] = max(+prices[index] - fee + dp[index+1][1], 0 + dp[index+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

//TC : O(n × 2) = O(n)
//SC : O(n × 2) = O(n)

//Space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
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
                    curr[buy] = max(+prices[index] - fee + ahead[1], 0 +ahead[0]);
                }
            }
            ahead = curr;
        }
        return curr[1];
    }
};

//TC : O(n × 2) = O(n)
//SC : O(1)

//Space Optimization using 4 variables
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        int aheadBuy = 0, aheadNotbuy = 0;

        for (int index = n-1; index >= 0; index--)
        {
            int currBuy = max(-prices[index] + aheadNotbuy, aheadBuy);
            int currNotbuy = max(prices[index] - fee + aheadBuy, aheadNotbuy);

            aheadBuy = currBuy;
            aheadNotbuy = currNotbuy;
        }

        return aheadBuy;
    }
};

//Time: O(N)
//Space: O(1) 
