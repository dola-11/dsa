//Recursive code
class Solution {
public:
    //i for pattern and j for strings
    bool recursion(int i, int j, string &s, string &p)
    {
        if (i<0 && j<0) return true;
        if (i<0 && j>=0) return false;

        if (j<0 && i>=0)
        {
            for (int ii=0; ii<=i; ii++)
            {
                if (p[ii] != '*') return false;
            }
            return true;
        }

        if(p[i] == s[j] || p[i] == '?') 
        {
            return recursion(i-1,j-1,s,p);
        }
        if (p[i] == '*') 
        {
            return recursion(i-1,j,s,p) || recursion(i,j-1,s,p);
        }
        return false;
    }
    bool isMatch(string s, string p) 
    {
        int psize = p.size();
        int strsize = s.size();

        return recursion(psize-1,strsize-1,s,p);
    }
};

//TC: O(2^(n+m)) 
//SC: O(n+m)

//Memoization
class Solution {
public:
    //i for pattern and j for strings
    bool recursion(int i, int j, string &s, string &p, vector<vector<int>>&dp)
    {
        if (i<0 && j<0) return true;
        if (i<0 && j>=0) return false;

        if (j<0 && i>=0)
        {
            for (int ii=0; ii<=i; ii++)
            {
                if (p[ii] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];
        if(p[i] == s[j] || p[i] == '?') 
        {
            return dp[i][j] = recursion(i-1,j-1,s,p,dp);
        }
        if (p[i] == '*') 
        {
            return dp[i][j] = recursion(i-1,j,s,p,dp) || recursion(i,j-1,s,p,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) 
    {
        int psize = p.size();
        int strsize = s.size();

        vector<vector<int>> dp (psize, vector<int>(strsize,-1));
        return recursion(psize-1,strsize-1,s,p,dp);
    }
};

//Time: O(n * m)
//Space: O(n * m) + O(n * m)

//1 based memoization
class Solution {
public:
    //i for pattern and j for strings
    bool recursion(int i, int j, string &s, string &p, vector<vector<int>>&dp)
    {
        if (i ==0 && j== 0) return true;
        if (i == 0 && j>0) return false;

        if (j == 0 && i > 0)
        {
            for (int ii=1; ii<=i; ii++)
            {
                if (p[ii-1] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];
        if(p[i-1] == s[j-1] || p[i-1] == '?') 
        {
            return dp[i][j] = recursion(i-1,j-1,s,p,dp);
        }
        if (p[i-1] == '*') 
        {
            return dp[i][j] = recursion(i-1,j,s,p,dp) || recursion(i,j-1,s,p,dp);
        }
        return false;
    }
    bool isMatch(string s, string p) 
    {
        int psize = p.size();
        int strsize = s.size();

        vector<vector<int>> dp (psize+1, vector<int>(strsize+1, -1));
 
        return recursion(psize,strsize,s,p,dp);
    }
};


//Tabulation
class Solution {
public:
    //i for pattern and j for strings
    bool isMatch(string s, string p) 
    {
        int psize = p.size();
        int strsize = s.size();

        vector<vector<bool>> dp (psize+1, vector<bool>(strsize+1, false));
        dp[0][0] = true;

        for (int j=1; j<strsize+1; j++)
        {
            dp[0][j] = false;
        }
        
        for (int i=1; i<psize+1; i++)
        {
            bool flag = true;
            for (int ii=1; ii<=i; ii++)
            {
                if (p[ii-1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i=1; i<psize+1; i++)
        {
            for(int j=1; j<strsize+1; j++)
            {
                if(p[i-1] == s[j-1] || p[i-1] == '?') 
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[i-1] == '*') 
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[psize][strsize];
    }
};
//Time: O(n * m)
//Space: O(n * m)


//space optimization
class Solution {
public:
    //i for pattern and j for strings
    bool isMatch(string s, string p) 
    {
        int psize = p.size();
        int strsize = s.size();

        vector<bool> prev(strsize+1,false);
        vector<bool> curr(strsize+1,false);

        prev[0] = true;

        for (int j=1; j<strsize+1; j++)
        {
            prev[j] = false;
        }
        
        
        for (int i=1; i<psize+1; i++)
        {
            //curr is the current row's column
            //curr's 0th row has to be assigned every time
            bool flag = true;
            for (int ii=1; ii<=i; ii++)
            {
                if (p[ii-1] != '*')
                {
                    flag = false;
                    break;
                }
            }

            curr[0] = flag; 

            for(int j=1; j<strsize+1; j++)
            {
                if(p[i-1] == s[j-1] || p[i-1] == '?') 
                {
                    curr[j] = prev[j-1];
                }
                else if (p[i-1] == '*') 
                {
                    curr[j] = prev[j] || curr[j-1];
                }
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[strsize];
    }
};


//Time: O(n * m)
//Space: O(m)
