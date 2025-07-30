class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.size();
        int m = s2.size();

        vector<int>mpp(26,0);
        vector<int>window(26,0);

        int left = 0;
        int right = 0;

        if (n>m) return false;

        for (int i=0; i<n; i++)
        {
            mpp[s1[i]-'a']++;
        }

        while(right<m)
        {
            window[s2[right]-'a']++;

            if(right-left+1>n)
            {
                window[s2[left]-'a']--;
                left++;
            }

            if (right-left+1 == n && window == mpp)
            {
                return true;
            }
            right++;
        }
        return false;
    }
};

//TC : O(M)
//SC : O(1)
