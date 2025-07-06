class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) 
    {
        // Your code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i = 0;
        int j = 0;
        int maxCount = 0;
        int count = 0;
        
        while(i<n && j<n)
        {
            if (arr[i] <= dep[j])
            {
                count = count + 1;
                i++;
            }
            else
            {
                count = count - 1;
                j++;
            }
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};

//TC : O(2N + 2NlogN)
//SC : O(1)
