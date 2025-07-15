class Solution {
public:
    bool isValid(string word) 
    {
        if (word.size()<3) return false;

        bool vowel = 0;
        bool consonent = 0;
        for(int i=0; i<word.size(); i++)
        {
            char c = word[i];
            if(!isalnum(c)) return false;
            if (isalpha(c))
            {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    vowel = true;
                }
                else
                {
                    consonent = true;
                }
            } 
        }

        return vowel && consonent;
    }
};

//TC : O(N)
//SC : O(1)
