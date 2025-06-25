class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,int> nge;
        stack<int>st;
        int n = nums2.size();

        for (int i = n - 1; i >= 0; i--) 
        {
            int num = nums2[i];
            // Pop elements smaller than or equal to current num
            while (!st.empty() && st.top() <= num) 
            {
                st.pop();
            }

            // If stack empty => no greater element
            if (st.empty()) nge[num] = -1;
            else nge[num] = st.top();

            // Push current number to stack
            st.push(num);
        }

        vector<int> ans;
        for (int num : nums1) 
        {
            ans.push_back(nge[num]);
        }

        return ans;
    }
};

//SC :  O(N) (stack + map)
//TC : O(N + M) (N = nums2.size(), M = nums1.size())
