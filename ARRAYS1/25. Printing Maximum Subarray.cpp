// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) 
    {
        // code here
        int n = arr.size();
        int currStart = 0;
        int ansStart = -1, ansEnd = -1;
        int currSum = 0;
        int maxSum = 0;
        
        for (int i=0; i<n; i++)
        {
            if (arr[i]<0)
            {
                currSum = 0;
                currStart = i+1;
                continue;
            }
            
            currSum += arr[i];
            
            if (currSum > maxSum)
            {
                maxSum = currSum;
                ansStart = currStart;
                ansEnd = i;
            }
            else if (currSum == maxSum)
            {
                int currLen = i - currStart + 1;
                int bestLen = (ansStart == -1) ? 0 : (ansEnd - ansStart + 1);
                if (currLen > bestLen || (currLen == bestLen && currStart < ansStart)) 
                {
                    ansStart = currStart;
                    ansEnd = i;
                }
            }
        }
        
        if (ansStart == -1) 
        {
            return {-1};
        }
        
        vector<int> ans;
        for (int i = ansStart; i <= ansEnd; i++) 
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

TC : O(n)
SC : O(N)
