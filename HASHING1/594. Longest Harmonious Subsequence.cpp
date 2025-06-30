class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        unordered_map<int,int> freq;
        int n = nums.size();
        //if (n==1) return 0;
        for(int x:nums)
        {
            freq[x] ++;
        }

        //if (freq.size() == 0)     //if all elements are equal
        //{
        //   return 0;
        //}

        int maxLen = 0;
        for (auto [x,f] : freq)
        {
            if (freq.count(x-1))
            {
                maxLen = max(maxLen, freq[x-1] + f);
            }
        }
        return maxLen;
    }
};

//TC : O(N)
//SC : O(N)
