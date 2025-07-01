class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector <int> mpp(256,-1);
        int right = 0;
        int left = 0;
        int maxlen = 0;
        int n = s.size();

        while(right<n)
        {
            if (mpp[s[right]] != -1)
            {
                left = max(mpp[s[right]]+1, left);
            }
            mpp[s[right]] = right;
            int len = right - left + 1;
            maxlen = max(maxlen,len);
            right++;
        }
        return maxlen;
    }
};

//TC : O(N)
//SC : O(1)
