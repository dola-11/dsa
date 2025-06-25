// User function Template for C++

class Solution {
  public:
    bool isOperand(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            return true;
        }
        return false;
    }
    string postToInfix(string exp) 
    {
        // Write your code here
        int size = exp.size();
        stack<string> st;
        
        for (int i=0; i<size; i++)
        {
            char ch = exp[i];
            
            if (isOperand(ch))
            {
                st.push(string(1, ch));
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                
                string converted = "(" + t2 + string(1, ch) + t1 + ")";
                st.push(converted);
            }
        }
        return st.top();
    }
};

//TC : O(n) 
//SC : O(n)
