class Solution {
  public:
    int priority(char c)
    {
        if (c == '^')
        {
            return 3;
        }
        else if (c == '/' || c == '*') return 2;
        
        else if (c == '+' || c == '-') return 1;
        
        else return -1;
    }
    
    string infixToPostfix(string& s) 
    {
        // code here
        stack <char> st;
        string result;
        
        for (int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0') && (ch <= '9'))
            {
                result += ch;
            }
            
            else if (ch == '(')
            {
                st.push('(');
            }
            else if(ch == ')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }
            else 
            {
                while(!st.empty() && priority(ch) <= priority(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty())
        {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};

| Complexity | Value                                |
| ---------- | ------------------------------------ |
| **Time**   | O(n)                                 |
| **Space**  | O(n) (for the stack + result string) |
