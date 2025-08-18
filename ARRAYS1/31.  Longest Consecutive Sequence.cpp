//brute approach:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        sort(nums.begin(),nums.end());
        int n = nums.size();

        int lastSmaller = INT_MIN;
        int cnt = 0;
        int longest = 1;

        for (int i=0; i<n; i++)
        {
            if (nums[i]-1 == lastSmaller)
            {
                cnt += 1;
                lastSmaller = nums[i];
            }
            else if (lastSmaller != nums[i])
            {
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest,cnt);
        }
        return longest;
    }
};

//TC : O(N) + O(nlogn)

//optimal
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();

        if (n<=1) return n;
        int longest = 1;
        unordered_set<int>st;

        for (int i=0; i<n; i++)
        {
            st.insert(nums[i]);
        }

        for (auto it:st)
        {
            if (st.find(it-1) == st.end())
            {
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end())
                {
                    x = x+1;
                    cnt = cnt+1;
                }
                longest = max(longest,cnt);
            }
        }

        return longest;
    }
};

//TC : O(N) + O(2N) = O(3N) - under the assumption that the set is taking O(1) {unordered set}
//SC : O(N)
