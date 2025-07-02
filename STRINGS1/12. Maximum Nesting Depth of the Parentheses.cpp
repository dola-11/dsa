class Solution {
public:
    int maxDepth(string s) 
    {
        int currentDepth = 0;
        int maxDepth = 0;

        for (char ch : s) 
        {
            if (ch == '(') 
            {
                currentDepth++;
                maxDepth = max(maxDepth, currentDepth);
            } 
            else if (ch == ')') 
            {
                currentDepth--;
                if (currentDepth < 0) return -1; // Invalid string
            }
        }

         return currentDepth == 0 ? maxDepth : -1; // Return -1 if unbalanced
    }
};

//TC : O(n)
//SC : O(1)
