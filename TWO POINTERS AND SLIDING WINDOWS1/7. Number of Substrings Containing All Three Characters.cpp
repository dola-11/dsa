//easier approach

class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int ans = 0;
        int len = s.length();
        int left = 0;
        int right = 0;
        vector<int>frequency(3,0);

        while(right<len)
        {
            char current = s[right];
            frequency[current - 'a']++;

            while(hasAllChars(frequency))
            {
                ans += len - right;

                char leftChar = s[left];
                frequency[leftChar - 'a'] --;
                left++;
            }
        right++;
        }
    return ans;
    }
    private: 
    bool hasAllChars(vector<int>& frequency)
    {
        return frequency[0] > 0 && frequency[1] > 0 && frequency[2] > 0;
    }
};

//TC : O(N)
//SC : O(1)

class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int len = s.length();
        vector<int>lastSeen(3,-1);
        int cnt = 0;

        for (int i=0; i<len; i++)
        {
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
            {
                cnt = cnt + 1 +min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }
        return cnt;
    }
};

//TC : O(n)
//SC : O(1)
