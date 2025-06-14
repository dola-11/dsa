class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) 
    {
        // Code here
        int n = arr.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        int maxi = 1;
        int lastIndex = 0;
        
        for (int index = 0; index <n ; index ++)
        {
            hash[index] = index;
            for (int prev = 0; prev < index; prev ++)
            {
                if (arr[index]>arr[prev] && dp[prev] + 1 > dp[index])
                {
                    dp[index] = dp[prev] + 1;
                    hash[index] = prev;
                }
            }
            if (dp[index] > maxi)
            {
                maxi = dp[index];
                lastIndex = index;
            }
        }
        
        vector<int>temp;
        temp.push_back(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

//TC: O(n²) 
//SC: O(n)

/*
Reconstruct LIS:
Start at lastIndex = 7 → arr[7] = 60 → temp = [60]

hash[7] = 5 → arr[5] = 50 → temp = [60, 50]

hash[5] = 3 → arr[3] = 33 → temp = [60, 50, 33]

hash[3] = 1 → arr[1] = 22 → temp = [60, 50, 33, 22]

hash[1] = 0 → arr[0] = 10 → temp = [60, 50, 33, 22, 10]

hash[0] = 0 → stop.

Now temp = [60, 50, 33, 22, 10] → reverse:

LIS = [10, 22, 33, 50, 60]
*/
