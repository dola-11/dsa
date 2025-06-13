//Recursive

class Solution {
public:
    int recursion(int index, int buy, vector<int>&prices)
    {
        int profit = 0;
        int n = prices.size();
        if (index >= n) return 0;
        if (buy == 1)
        {
            profit = max(-prices[index] + recursion(index+1,0,prices), 0 + recursion(index+1,1,prices));
        }
        else if (buy == 0)
        {
            profit = max(+prices[index] + recursion(index+2,1,prices), 0 + recursion(index+1,0,prices));
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        return recursion(0, 1, prices);
    }
};

//Time:O(2^n)
//Space:O(n)

//Memoization
class Solution {
public:
    int recursion(int index, int buy, vector<int>&prices, vector<vector<int>>&dp)
    {
        int profit = 0;
        int n = prices.size();
        if (index >= n) return 0;
        if (dp[index][buy] != -1) return dp[index][buy];

        if (buy == 1)
        {
            profit = max(-prices[index] + recursion(index+1,0,prices,dp), 0 + recursion(index+1,1,prices,dp));
        }
        else if (buy == 0)
        {
            profit = max(+prices[index] + recursion(index+2,1,prices,dp), 0 + recursion(index+1,0,prices,dp));
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        return recursion(0, 1, prices,dp);
    }
};

//Space:O(n)
//Time:O(n)

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2,0));

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
                    dp[index][buy] = max(+prices[index] + dp[index+2][1], 0 + dp[index+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
//TC : O(n)
//SC : O(1)

//Space optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>ahead(2,0);
        vector<int>ahead2(2, 0);

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
                    curr[buy] = max(+prices[index] + ahead2[1], 0 +ahead[0]);
                }
            }
            ahead2 = ahead;
            ahead = curr;
        }
        return curr[1];
    }
};

//TC : O(n)
//SC : O(1)
