//Recursion 
class Solution {
public:
    int f(int i, vector<int> & heights, int k)
    {
        if (i==0) return 0;
        int minSteps = INT_MAX;

        for (int j=1; j<=k; j++)
        {
            if (i-j >= 0)
            {
                int jump = f(i-j,heights,k) + abs(heights[i]-heights[i-j]);
                minSteps = min(minSteps, jump);
            }
        }
        return minSteps;
    }

    int frogJump(vector<int>& heights, int k) 
    {
        int n = heights.size();
        return f(n-1,heights,k);
    }
};

//SC : O(n)
//TC : O(k^n)

//Memoization 
class Solution {
public:
    int f(int i, vector<int> & heights, int k, vector<int>& dp)
    {
        if (i==0) return 0;
        if (dp[i]!= -1) return dp[i];

        int minSteps = INT_MAX;

        for (int j=1; j<=k; j++)
        {
            if (i-j >= 0)
            {
                int jump = f(i-j,heights,k) + abs(heights[i]-heights[i-j]);
                minSteps = min(minSteps, jump);
            }
        }
        return dp[i] = minSteps;
    }

    int frogJump(vector<int>& heights, int k) 
    {
        int n = heights.size();
        vector<int> dp(n,-1);
        return f(n - 1, heights, k, dp);
    }
};

//SC : O(n) + O(n)
//TC : O(n*k)

//Tabulation
class Solution {
public:
    int frogJump(vector<int>& heights, int k) 
    {
        int n = heights.size();
        vector<int>dp(n,0);

        dp[0]=0;

        for (int i=1; i<n; i++)
        {
            int minSteps = INT_MAX;

            for (int j=1; j<=k; j++)
            {
                if (i-j>=0)
                {
                    int jump = dp[i-j] + abs(heights[i]-heights[i-j]);
                    minSteps = min(minSteps, jump);
                }
            }
            dp[i] = minSteps;
        }
        return dp[n-1];
    }
};
//SC : O(n) 
//TC : O(n*k)

//Space Optimization:
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(k + 1, 0);  // Only keep last k values

        for (int i = 1; i < n; i++) {
            int minSteps = INT_MAX;

            for (int j = 1; j <= k && i - j >= 0; j++) {
                int jump = dp[(i - j) % (k + 1)] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, jump);
            }

            dp[i % (k + 1)] = minSteps;  // Overwrite old value
        }

        return dp[(n - 1) % (k + 1)];
    }
};

//SC: O(k)
//TC : O(n*k)
