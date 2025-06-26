class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;

        int size = s.size();
        for (int i=0; i<size; i++)
        {
            if (s[i] == '(' || s[i] == '{'|| s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty()) return false;
                char ch = st.top();
                st.pop();
                if ((ch == '(' && s[i] != ')') ||
                    (ch == '{' && s[i] != '}') ||
                    (ch == '[' && s[i] != ']'))
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

//Time: O(n)
//Space: O(n) (stack space in worst case all opening brackets)
