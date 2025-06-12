//Recursion

class Solution {
public:
    int recurrence(int i, int j, string word1, string word2)
    {
        if (i<0) return j+1;
        if (j<0) return i+1;

        if(word1[i] == word2[j]) return 0 + recurrence(i-1,j-1,word1,word2);
        else
        {
            return 1+ min(recurrence(i,j-1,word1,word2),min(recurrence(i-1,j,word1,word2),recurrence(i-1,j-1,word1,word2)));
        }

    }
    int minDistance(string word1, string word2) 
    {
        int size1 = word1.size();
        int size2 = word2.size();
        return recurrence(size1-1,size2-1,word1,word2);
    }
};

//TC: O(3^{n + m})
//SC: O(n+m)


//THE RECURSION TREE
/*
recurrence(1, 1)
|
|-- word1[1] != word2[1] ("b" != "c") → 3 branches:
|   
|-- recurrence(1, 0)     (INSERT)
|   |
|   |-- word1[1] != word2[0] ("b" != "a")
|   |-- 3 branches:
|   |   
|   |-- recurrence(1, -1) --> returns 1+1 = 2
|   |-- recurrence(0, 0)
|   |   |
|   |   |-- word1[0] == word2[0] ("a" == "a")
|   |   |-- recurrence(-1, -1) --> returns 0
|   |   --> returns 0
|   |-- recurrence(0, -1) --> returns 1+1 = 2
|   --> min(2, 0, 2) + 1 = 1
|
|-- recurrence(0, 1)     (DELETE)
|   |
|   |-- word1[0] != word2[1] ("a" != "c")
|   |-- 3 branches:
|   |   
|   |-- recurrence(0, 0)
|   |   |
|   |   |-- word1[0] == word2[0] ("a" == "a")
|   |   |-- recurrence(-1, -1) --> returns 0
|   |   --> returns 0
|   |-- recurrence(-1, 1) --> returns 2
|   |-- recurrence(-1, 0) --> returns 1
|   --> min(0, 2, 1) + 1 = 1
|
|-- recurrence(0, 0)     (replace)
|   |
|   |-- word1[0] == word2[0] ("a" == "a")
|   |-- recurrence(-1, -1) --> returns 0
|   --> returns 0
|
--> min(1, 1, 0) + 1 = 1
*/

//MEMOIZATION
class Solution {
public:
    int recurrence(int i, int j, string word1, string word2,vector<vector<int>> &dp)
    {
        if (i<0) return j+1;
        if (j<0) return i+1;

        if (dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = 0 + recurrence(i-1,j-1,word1,word2,dp);
        else
        {
            return dp[i][j] = 1+ min(recurrence(i,j-1,word1,word2,dp),min(recurrence(i-1,j,word1,word2,dp),recurrence(i-1,j-1,word1,word2,dp)));
        }

    }
    int minDistance(string word1, string word2) 
    {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size1, vector<int>(size2,-1));
        return recurrence(size1-1,size2-1,word1,word2,dp);
    }
};

//Time: O(n * m)
//Space: O(n * m) for dp + O(n + m) for recursion stack.

//1 based indexing
class Solution {
public:
    int recurrence(int i, int j, string word1, string word2,vector<vector<int>> &dp)
    {
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];
        if(word1[i-1] == word2[j-1]) return dp[i][j] = 0 + recurrence(i-1,j-1,word1,word2,dp);
        else
        {
            return dp[i][j] = 1+ min(recurrence(i,j-1,word1,word2,dp),min(recurrence(i-1,j,word1,word2,dp),recurrence(i-1,j-1,word1,word2,dp)));
        }

    }
    int minDistance(string word1, string word2) 
    {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1,-1));
        return recurrence(size1,size2,word1,word2,dp);
    }
};

//Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size1+1, vector<int>(size2+1,0));

        for (int i=0; i<=size1; i++) dp[i][0] = i;
        for (int j=0; j<=size2; j++) dp[0][j] = j;

        for (int i=1; i<=size1; i++)
        {
            for (int j=1; j<=size2; j++)
            {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[size1][size2];
    }
};

//Time: O(n * m)
//Space: O(n * m)

//Space optimization
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<int>prev(size2+1,0);
        vector<int>curr(size2+1,0);

        for (int j=0; j<=size2; j++) prev[j] = j;

        for (int i=1; i<=size1; i++)
        {
            curr[0] = i;
            for (int j=1; j<=size2; j++)
            {
                if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
                else
                {
                    curr[j] = 1 + min(prev[j], min(curr[j-1], prev[j-1]));
                }
            }
            prev = curr;
        }
        return prev[size2];
    }
};

//Time : 	O(size1 * size2)
//Space : 	O(size2)
