class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) 
    {
        // code here
        int n = arr.size();
        vector<int>nse(n);
        stack<int>st;
        
        for (int i=0; i<n; i++)
        {
            while(!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return nse;
    }
};

//TC : O(N)
//SC : O(N), The output array is typically not counted in auxiliary space. If so, auxiliary space = O(n) for the stack.
