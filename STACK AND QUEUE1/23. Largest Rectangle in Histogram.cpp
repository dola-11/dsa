//method 1

class Solution {
public:
    vector<int> findNSE(vector<int>&heights)
    {
        int n = heights.size();
        vector<int>nse(n);
        stack<int>st;

        for (int i=n-1; i>=0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int>&heights)
    {
        int n = heights.size();
        vector<int>pse(n);
        stack<int>st;

        for(int i=0; i<n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        vector<int>nse = findNSE(heights);
        vector<int>pse = findPSE(heights);
        int maxi = 0;

        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }
};

//TC : O(3N)
//SC : O(4N)

//2nd method
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int maxArea = 0;
        int n = heights.size();
        stack<int> st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, heights[element] * (nse - pse -1));
            }
            st.push(i);
        }

        while(!st.empty())
        {
            int nse = n;
            int element = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, heights[element] * (nse - pse -1));
        }
        return maxArea;
    }
};

//TC : O(2N)
//SC : O(N)
