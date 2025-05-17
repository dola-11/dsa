//Recursion

class Solution {
  public:
    int f(int i, vector<int>& height) 
    {
        if (i == 0) return 0;
        if (i == 1) return abs(height[1] - height[0]);

        int oneJump = f(i - 1, height) + abs(height[i] - height[i - 1]);
        int twoJump = f(i - 2, height) + abs(height[i] - height[i - 2]);

        return min(oneJump, twoJump);
    }

    int minCost(vector<int>& height) 
    {
        int n = height.size();
        return f(n - 1, height);  
    }
};
//TC : O(2^n), SC : O(n)

//Memoization
class Solution {
  public:
    int f(int i, vector<int>& height, vector<int> &dp) 
    {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];      //Memoization step: if value is already computed, reuse it
        

        int oneJump = f(i - 1, height,dp) + abs(height[i] - height[i - 1]);
        
        int twoJump = INT_MAX;
        if (i>1)
            twoJump = f(i - 2, height,dp) + abs(height[i] - height[i - 2]);

        return dp[i] =  min(oneJump, twoJump);
    }

    int minCost(vector<int>& height) 
    {
        int n = height.size();
        vector<int> dp(n,-1);
        return f(n - 1, height, dp);  
    }
};
//TC : O(n), SC : O(n)


//Tabulation
class Solution {
  public:
    int minCost(vector<int>& height) 
    {
        // Code here
        int n = height.size();
        vector<int> dp(n,0);
        
        dp[0]=0;
        for (int i=1; i<n; i++)
        {
            int oneJump = dp[i-1] + abs(height[i]-height[i-1]);
            
            int twoJump = INT_MAX;
            if (i>1)
            {
                twoJump = dp[i-2] + abs(height[i]-height[i-2]);
            }
            
            dp[i] = min(oneJump,twoJump);
        }
        return dp[n-1];
    }
};
//TC : O(n), SC : O(n)

//Space optimization
class Solution {
  public:
    int minCost(vector<int>& height) 
    {
        // Code here
        int n = height.size();
        
        if (n==1) return 0;
        
        int prev2 = 0;
        int prev1 = 0;
        
        for (int i=1; i<n; i++)
        {
            int current = prev1 + abs(height[i]-height[i-1]);
            
            if (i>1)
            {
                current = min(current, prev2 + abs(height[i]-height[i-2]));
            }
             
            prev2 = prev1;
            prev1 = current;
            
        }
        return prev1;
    }
};
//TC : O(n), SC : O(1)
