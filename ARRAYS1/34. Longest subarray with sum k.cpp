//better - for positives,negatives and zeroes

#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) 
{
    // Write your code here
    map<long long,int> prefixMap;
    long long sum = 0;
    int len = 0;

    for (int i=0; i<a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
        {
            len = max(len,i+1);
        }

        long long rem = sum - k;
        if (prefixMap.find(rem)!=prefixMap.end())
        {
            int currlen = i - prefixMap[rem];
            len = max(len,currlen);
        }
        
        if (prefixMap.find(sum) == prefixMap.end())
        {
            prefixMap[sum] = i;
        }
        
    }
    return len;
}

//TC : O(n log n)
//SC : O(n)


//optimal soln for positives, contacted
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int left = 0;
        int right =0;

        long long sum = nums[0];
        int maxlen = 0;
        int n = nums.size();

        while(right<n)
        {
            while(left<right && sum >k)
            {
                sum -= nums[left];
                left++;
            }
            if (sum == k)
            {
                maxlen = max(maxlen, right-left+1);
            }
            right++;
            if (right<n)
            {
                sum += nums[right];
            } 
        }
        return maxlen;
    }
};

//TC : O(n*2)
//SC : O(1)
