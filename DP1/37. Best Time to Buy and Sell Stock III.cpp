//1st method

//Recursion
class Solution {
public:
    int recursion(int index, int buy, int capacity, vector<int>&prices)
    {
        int n = prices.size();
        if (index == n) return 0;
        if (capacity == 0) return 0;
        int profit = 0;

        if (buy == 1)
        {
            profit = max(- prices[index] + recursion(index+1,0,capacity,prices), 0 + recursion(index+1,1,capacity,prices));
        }
        if (buy == 0)
        {
            profit = max(prices[index]+ recursion(index+1,1,capacity-1,prices), 0 + recursion(index+1,0,capacity,prices));
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        return recursion(0,1,2,prices);
    }
};

//Time:O(2^n)
//Space:O(n)

//Memoization
class Solution {
public:
    int recursion(int index, int buy, int capacity, vector<int>&prices, vector<vector<vector<int>>> &dp)
    {
        int n = prices.size();
        if (index == n) return 0;
        if (capacity == 0) return 0;
        int profit = 0;

        if (dp[index][buy][capacity] != -1) return dp[index][buy][capacity];

        if (buy == 1)
        {
            profit = max(- prices[index] + recursion(index+1,0,capacity,prices,dp), 0 + recursion(index+1,1,capacity,prices,dp));
        }
        if (buy == 0)
        {
            profit = max(prices[index]+ recursion(index+1,1,capacity-1,prices,dp), 0 + recursion(index+1,0,capacity,prices,dp));
        }
        return dp[index][buy][capacity] = profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2, vector<int>(3,-1)));
        return recursion(0,1,2,prices,dp);
    }
};

//TC : O(n×2×3) ≈O(n)
//SC : DP table size = O(n*2*3) = O(n), Recursion stack space = O(n).

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int profit = 0;

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2, vector<int>(3,0)));
        //since we already initialise the dp table with 0's we don't need to code the base cases separately (if base cases had values other than zero, then we have to)

        for (int index = n-1; index>=0; index--)
        {
            for (int buy = 0; buy <=1; buy++)
            {
                for (int capacity = 1; capacity <=2; capacity++)
                {
                    if (buy == 1)
                    {
                        profit = max(- prices[index] + dp[index+1][0][capacity], 0 + dp[index+1][1][capacity]);
                    }
                    if (buy == 0)
                    {
                        profit = max(prices[index]+ dp[index+1][1][capacity-1], 0 + dp[index+1][0][capacity]);
                    }
                    dp[index][buy][capacity] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};

//Space : O(n)
//Time : O(n)

//Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();

        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        //since we already initialise the dp table with 0's we don't need to code the base cases separately (if base cases had values other than zero, then we have to)

        for (int index = n-1; index>=0; index--)
        {
            for (int buy = 0; buy <=1; buy++)
            {
                for (int capacity = 1; capacity <=2; capacity++)
                {
                    int profit = 0;
                    if (buy == 1)
                    {
                        profit = max(- prices[index] + ahead[0][capacity], 0 + ahead[1][capacity]);
                    }
                    if (buy == 0)
                    {
                        profit = max(prices[index]+ ahead[1][capacity-1], 0 + ahead[0][capacity]);
                    }
                    curr[buy][capacity] = profit;
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};

//Space : O(1)
//Time : O(n)


//2nd method

//Recursive
class Solution {
public:
    int recursion(int index, int transactions, vector<int>& prices)
    {
        int n = prices.size();

        if (index == n || transactions == 4) return 0;
        int profit = 0;

        if(transactions%2 == 0)
        {
            profit = max(- prices[index] + recursion(index+1,transactions+1,prices), 0 + recursion(index+1,transactions,prices));
        }

        if(transactions%2 != 0)
        {
            profit = max(prices[index]+ recursion(index+1,transactions+1,prices), 0 + recursion(index+1,transactions,prices));
        }
        
        return profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        return recursion(0,0,prices);
    }
};

//Space: O(N×5)≈O(N)
//Time: O(2^N)

//Memoization
class Solution {
public:
    int recursion(int index, int transactions, vector<int>& prices, vector<vector<int>> &dp)
    {
        int n = prices.size();

        if (index == n || transactions == 4) return 0;

        if (dp[index][transactions] != -1) return dp[index][transactions];

        int profit = 0;
        if(transactions%2 == 0)
        {
            profit = max(- prices[index] + recursion(index+1,transactions+1,prices,dp), 0 + recursion(index+1,transactions,prices,dp));
        }

        if(transactions%2 != 0)
        {
            profit = max(prices[index]+ recursion(index+1,transactions+1,prices,dp), 0 + recursion(index+1,transactions,prices,dp));
        }
        
        return dp[index][transactions] = profit;
    }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, -1));  //2*2+1,transactions → possible values: 0,1,2,3,4 → so 5 columns.
        return recursion(0,0,prices,dp);
    }
};

//Time: O(N * 5) → O(N)
//Space: O(N * 5) 

//Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5, 0));  //2*2+1,transactions → possible values: 0,1,2,3,4 → so 5 columns.
        for (int index = n-1; index>=0; index--)
        {
            for (int transNo = 2*2-1; transNo >= 0; transNo --)
            {
                if(transNo%2 == 0)
                {
                    dp[index][transNo] = max(- prices[index] + dp[index+1][transNo+1], 0 + dp[index+1][transNo]);
                }

                if(transNo%2 != 0)
                {
                    dp[index][transNo] = max(prices[index]+ dp[index+1][transNo+1], 0 + dp[index+1][transNo]);
                }
            }
        }
        return dp[0][0];
    }
};

//Time:T(n)=n×4=O(n)
//Space:S(n)=(n+1)×5=O(n)

//Space optimixation
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> ahead(5, 0);
        vector<int> curr(5, 0); 

        for (int index = n-1; index>=0; index--)
        {
            for (int transNo = 2*2-1; transNo >= 0; transNo --)
            {
                if(transNo%2 == 0)
                {
                    curr[transNo] = max(- prices[index] + ahead[transNo+1], 0 + ahead[transNo]);
                }

                if(transNo%2 != 0)
                {
                    curr[transNo] = max(prices[index]+ ahead[transNo+1], 0 + ahead[transNo]);
                }
            }
            ahead = curr;
        }
        return ahead[0];
    }
};

//Time: O(N * 4) = O(N)
//Space: O(5) = O(1)
