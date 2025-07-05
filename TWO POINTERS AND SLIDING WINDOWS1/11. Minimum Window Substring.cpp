//Difficult question

class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int>hashFreq(256,0);
        int left = 0;
        int right = 0;
        int minLen = 1e9;
        int startIndex = -1;
        int count = 0;

        for (int i=0; i<t.size(); i++)
        {
            hashFreq[t[i]]++;
        }
        while(right < s.size())
        {
            if(hashFreq[s[right]]>0)
            {
                count++;
            }
            hashFreq[s[right]]--;

            while(count == t.size())
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                hashFreq[s[left]]++;
                if(hashFreq[s[left]]>0)
                {
                    count = count-1; 
                }
                left++;  
            }
            right = right + 1;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
//TC : O(m + n) 
//SC : O(1)

/*
Frequency Map Setup:

Use a hashFreq[256] array to store the frequency of each character in t.

Sliding Window:

Use two pointers left and right to define the window in s.

Expand the right pointer to include characters.

If a required character is found (hashFreq[s[right]] > 0), increment the count.

Always decrement hashFreq[s[right]] to mark that character as used.

Window Validity Check:

When count == t.size(), it means all required characters (including duplicates) have been matched.

Try to shrink the window from the left to find the smallest valid window.

Update the result if the current window is smaller than the previous minimum.

Window Shrinking:

Restore the character at s[left] back to hashFreq.

If this character becomes positive again, it means a required character has been removed — decrement count.

Final Result:

If a valid window was found, return the substring starting at startIndex with length minLen.

Otherwise, return "".
*/
