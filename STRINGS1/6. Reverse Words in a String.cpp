class Solution {
public:
    string reverseWords(string s) 
    {
        reverse(s.begin(),s.end());
        string ans = "";

        string word = "";
        int i = 0;
        int n = s.size();

        while(i<n)
        {
            if (s[i] != ' ')
            {
                word += s[i];
            }
            else
            {
                if (!word.empty())
                {
                    reverse(word.begin(), word.end());
                    if (!ans.empty()) ans += " ";
                    ans += word;
                    word = "";
                }
            }
            i++;
        }

        // Handle the last word (if any)
        //If the string ends with a word and not a space, the last word will never get added inside the loop.
        if (!word.empty()) 
        {
            reverse(word.begin(),word.end());
            if (!ans.empty()) ans += " ";
            ans += word;
        }
        return ans;
    }
};

/*
Time Complexity: O(n)
Where n = s.size()
Here's the breakdown:
reverse(s.begin(), s.end()): O(n)
The while loop visits each character once: O(n)
Reversing each word inside the loop: total O(n) across all words
Final concatenation into ans: O(n)

So, total time is O(n)

Space Complexity: O(n)
word stores characters of a word temporarily → max O(n)
ans stores the final string → O(n)
You are not modifying s in-place and instead build a new ans string → O(n) extra space
So, space complexity is O(n)
*/

class Solution {
public:
    string reverseWords(string s) 
    {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i=0; i<n; i++)
        {
            string word = "";
            while(i<n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            reverse(word.begin(),word.end());
            if (word.length() > 0)
            {
                ans += " " + word;
            }
        }
        return ans.substr(1);    //for the starting space
    }
};

//two pointer

class Solution {
public:
    void reverse(string &s, int left, int right)
    {
        while(left < right)
        {
            swap(s[left++],s[right--]);
        }
    }

    string reverseWords(string s) 
    {
        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;

        while(i<n)
        {
            while(i<n && s[i] == ' ') i++;

            while(i<n && s[i] != ' ')
            {
                if (right != 0)
                {
                    s[right++] = ' '; 
                }
                while (i < n && s[i] != ' ') 
                {
                    s[right++] = s[i++];
                }
            }
        }  
        s.resize(right);

        reverse(s, 0, s.size() - 1);

        int start = 0;
        for (int end = 0; end <= s.size(); ++end) 
        {
            if (end == s.size() || s[end] == ' ') 
            {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }
        return s;
    }
};

/*
Time: O(n)

Clean up string: O(n)
Reverse entire string: O(n)
Reverse each word: O(n)
Space: O(1) extra (in-place)
*/
