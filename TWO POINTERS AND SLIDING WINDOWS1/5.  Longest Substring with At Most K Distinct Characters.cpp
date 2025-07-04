#include <unordered_map>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    int left = 0;
    int right = 0;
    int maxlen = 0;
    int n = str.size();
    unordered_map<char,int> charHash;

    while(right < n)
    {
        charHash[str[right]]++;
        if(charHash.size()>k)
        {
            charHash[str[left]]--;
            if(charHash[str[left]] == 0)
            {
                charHash.erase(str[left]);
            }
            left++;
        }
        else
        {
            maxlen = max(maxlen, right-left+1);
        }
        right = right + 1;
    }
    return maxlen;
}

//TC : O(N) + O(256) = O(n)
//SC : O(256) = O(k)
