//My soln (two pass)

class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi,nums[i]);
        }

        int maxlen = 0;
        for (int i=0; i<n; i++)
        {
            int currlen = 0;
            while(i < n && nums[i] == maxi)
            {
                currlen++;
                i++;
            }
            maxlen = max (maxlen, currlen);
        }
        return maxlen;
    }
};

//TC : O(2N)
//SC : O(1)


//One pass approach
class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxi = INT_MIN;
        int currlen = 0;
        int maxlen = 0;

        for (int num : nums)
        {
            if (num == maxi)
            {
                currlen ++;
            }
            else if (num > maxi)
            {
                maxi = num;
                currlen = 1;
                maxlen = 1;
            }
            else
            {
                currlen = 0;
            }
            maxlen = max(maxlen,currlen);
        }
        return maxlen;
    }
};

//TC : O(N)
//SC : O(1)
