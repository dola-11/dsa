//Recursive solution:
//gives TLE

bool backtrack(string s, unordered_set<string>& wordSet, int index)
{
    // Base case: if we have reached the end of the string successfully,
    // it means the entire string can be segmented.
    if (index == s.length()) return true;

    // Try every possible substring starting from 'index' to the end of the string.
    for (int i = index + 1; i <= s.length(); i++)
    {
        // Extract the substring from 'index' up to 'i' (not including 'i')
        string prefix = s.substr(index, i - index);

        // Check if the prefix is in the dictionary
        if (wordSet.count(prefix))
        {
            // If prefix is found, recursively check for the rest of the string starting from 'i'
            if (backtrack(s, wordSet, i))
                return true; // If successful, return true immediately
        }
    }

    // If no segmentation works, return false
    return false;
}


bool wordBreak(string s, vector<string>& wordDict) 
{
    // Convert vector dictionary to unordered_set for O(1) lookup
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    // Start backtracking from index 0
    return backtrack(s, wordSet, 0);
}

//TC : Exponential O(2^n)
//SC : O(n) (recursive stack) and O(m*k) for dictionary


//tabulation code
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;  // empty string can always be segmented

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;  // no need to check further if dp[i] is true
            }
        }
    }

    return dp[n];
}

//TC : O(n³)
//SC : 	O(n + total dictionary size)
