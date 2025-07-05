class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int right = 0;
        int left = 0;
        int maxlen = 0;
        int maxfreq = 0;
        vector<int>mpp(26,0);
        int n = s.size();

        while(right<n)
        {
            mpp[s[right] - 'A']++;
            maxfreq = max(maxfreq, mpp[s[right]-'A']);
            if((right-left+1)-maxfreq > k)
            {
                mpp[s[left] - 'A']--;
                left++;
            }
            else
            {
                maxlen = max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};

//TC : O(n)
//SC : O(1)
