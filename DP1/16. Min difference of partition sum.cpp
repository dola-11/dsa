//Tabulation

class Solution {

  public:
  
    int minDifference(vector<int>& arr) 
    {
        // Your code goes here
        int totalSum = 0;
        int n = arr.size();
        for (int i=0; i<n; i++)
        {
            totalSum += arr[i];
        }
        
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
        for (int i=0; i<n; i++)
        {
            dp[i][0] = true;
        }
        
        if (arr[0] <= totalSum)
        {
            dp[0][arr[0]] = true;
        }
        
        for (int index = 1; index <n; index++)
        {
            for (int target = 1; target <=totalSum; target ++)
            {
                bool take = false;
                bool notTake = dp[index-1][target];
                
                if (arr[index]<=target)
                {
                    take = dp[index-1][target-arr[index]];
                }
                dp[index][target] = take || notTake;
            }
        }
        
        //dp[n-1][col -> 0...totalSum] will tell us whether particular sum is possible
        int mini = 1e9;
        for (int s1 = 0; s1<=totalSum/2; s1++)
        {
            if(dp[n-1][s1] == true)
            {
                int subset1 = s1;
                int subset2 = totalSum - s1;
                mini = min(mini,abs(subset1-subset2));
            }
        }
        return mini;
    }
};

//Time: O(n × totalSum)
//Space: O(n × totalSum)


//Space Optimization
class Solution {

  public:
  
    int minDifference(vector<int>& arr) 
    {
        // Your code goes here
        int totalSum = 0;
        int n = arr.size();
        for (int i=0; i<n; i++)
        {
            totalSum += arr[i];
        }
        
        vector<bool>prev(totalSum+1,0);
        vector<bool>curr(totalSum+1,0);
        
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;
        
        for (int index = 1; index <n; index++)
        {
            for (int target = 1; target <=totalSum; target ++)
            {
                bool take = false;
                bool notTake = prev[target];
                
                if (arr[index]<=target)
                {
                    take = prev[target-arr[index]];
                }
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        
        //dp[n-1][col -> 0...totalSum] will tell us whether particular sum is possible
        int mini = 1e9;
        for (int s1 = 0; s1<=totalSum/2; s1++)
        {
            if(prev[s1] == true)
            {
                int subset1 = s1;
                int subset2 = totalSum - s1;
                mini = min(mini,abs(subset1-subset2));
            }
        }
        return mini;
    }
};

//Time Complexity: O(n * totalSum)
//Space Complexity: O(totalSum)
