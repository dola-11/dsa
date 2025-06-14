class Solution {
public:
    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

    bool compare(string prev, string curr)
    {
        if (curr.size() - prev.size() != 1) return false;

        int i =0;
        int j =0;

        while(i<curr.size())
        {
            if (j<prev.size() && curr[i] == prev[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        if(i == curr.size() && j == prev.size()) return true;
        return false;
    }

    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(),words.end(),comp);
        int n = words.size();
        vector<int>dp(n,1);
        int maxi = 1;

        for (int index = 0; index<n; index++)
        {
            for (int prev = 0; prev<index; prev++)
            {
                if (compare(words[prev], words[index]) && 1 + dp[prev] > dp[index])
                {
                    dp[index] = dp[prev] + 1;
                }
            }
            maxi = max(maxi,dp[index]);
        }
        return maxi;
    }
};

/* Time Complexity
Sorting: O(N log N)
DP nested loop: O(N²)
Compare function: O(L) where L is max word length.
O(NlogN+N² * L)

Space: O(N)
*/
