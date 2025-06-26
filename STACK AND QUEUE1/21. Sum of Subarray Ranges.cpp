class Solution {
public:
    vector<int> findNSE(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>nse(n);
        stack<int>st;

        for (int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>psee(n);
        stack<int>st;

        for(int i=0; i<n;i++)
        {
            while(!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    vector<int> findNLE(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>nle(n);
        stack<int>st;

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nle;
    }

    vector<int> findPLEE(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>plee(n);
        stack<int>st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
            {
                st.pop();
            }
            plee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return plee;
    }

    long long subArrayRanges(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>nse = findNSE(nums);
        vector<int>psee = findPSEE(nums);
        vector<int>nle = findNLE(nums);
        vector<int>plee = findPLEE(nums);

        long long total = 0;
        for (int i=0; i<n; i++)
        {
            long long leftSmall = i - psee[i];
            long long rightSmall = nse[i] - i;
            long long leftLarge = i - plee[i];
            long long rightLarge = nle[i] - i;

            total += leftLarge * rightLarge * nums[i];
            total -= leftSmall * rightSmall * nums[i];
        }
        return total;
    }
};

//TC : O(5*N)
//SC : O(5*N)
