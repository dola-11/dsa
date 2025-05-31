class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int lenstr1 = str1.size();
        int lenstr2 = str2.size();

        vector<vector<int>>dp(lenstr1+1,vector<int>(lenstr2+1,0));

        for (int i=0; i<=lenstr1; i++) dp[i][0] = 0;
        for (int j=0; j<=lenstr2; j++) dp[0][j] = 0;

        for (int i=1; i<=lenstr1; i++)
        {
            for (int j=1; j<=lenstr2; j++)
            {
                if (str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string ans = "";
        int i = lenstr1;
        int j = lenstr2;

        while (i>0 && j>0)
        {
            if (str1[i-1] == str2[j-1])
            {
                ans += str1[i-1];
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1])   //upwards
            {
                ans += str1[i-1];
                i--;
            }
            else                                //left dir
            {
                ans += str2[j-1];
                j--;
            }
        }

        while(i>0)
        {
            ans+= str1[i-1];
            i--;
        } 

        while(j>0)
        {
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//TC : O(n×m)
​//SC : O(n×m)
