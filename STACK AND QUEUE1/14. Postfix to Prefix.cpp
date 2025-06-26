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
    
    string postToPre(string post_exp) 
    {
        // Write your code here
        int size = post_exp.size();
        stack<string> st;
        
        for (int i=0; i<size; i++)
        {
            char ch = post_exp[i];
            
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
                
                st.push(ch + t2 + t1);
            }
        }
        return st.top();
    }
};

//TC : O(N)
//SC : O(N)
