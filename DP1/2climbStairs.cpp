class Solution {
public:
    int climbStairs(int n) 
    {
        if (n==1) return 1;
        if (n==2) return 2;
        if (n==3) return 3;

        int prev1 = 3;
        int prev2 = 2;
        int latest = 0;

        for (int i=3; i<n; i++)
        {
            latest = prev1 + prev2;
            prev2 = prev1;
            prev1 = latest;
        }
        
        return latest;
    }
};

//TC : O(n), SC: O(1)
