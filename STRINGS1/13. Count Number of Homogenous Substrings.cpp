class Solution {
public:
    const int mod = 1000000007;

    int countHomogenous(string s) 
    {
        int noOfSubstrings = 0;
        int currentCnt = 1;
        int n = s.size();

        for(int i=1; i<n; i++)
        {
            if (s[i] == s[i-1])
            {
                currentCnt++;
            }
            else
            {
                noOfSubstrings = (noOfSubstrings + 1LL * currentCnt * (currentCnt+1)/2) % mod;
                currentCnt = 1;
            }
        } 

        //adding the last grp
        noOfSubstrings = (noOfSubstrings + 1LL * currentCnt * (currentCnt+1)/2) % mod;

        return noOfSubstrings;
    }
};

//TC : O(N)
//SC : O(1)
