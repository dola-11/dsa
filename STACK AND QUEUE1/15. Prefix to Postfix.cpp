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
    
    string preToPost(string pre_exp) 
    {
        int size = pre_exp.size();
        stack<string> st;
        
        for (int i=size-1; i>=0; i--)
        {
            char ch = pre_exp[i];
            
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
                
                st.push(t1 + t2 + ch);
            }
        }
        return st.top();
    }
};

//TC : O(N)
//SC : O(N)
