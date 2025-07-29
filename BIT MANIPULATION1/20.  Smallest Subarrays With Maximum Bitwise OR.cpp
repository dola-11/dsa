//Brute force gives TLE
//TLE code-
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n);
        int maxOR = 0;

        for(int i=0; i<n; i++)
        {
            int targetOR = 0;
            for (int k = i; k < n; k++) 
            {
                targetOR |= nums[k];
            }

            int currOR = 0;
            for (int j=i; j<n; j++)
            {
                currOR |= nums[j];
                if (currOR == targetOR)
                {
                    ans.push_back(j-i+1);
                    break;
                }
            }
        }
        return ans;
    }
};


//TC :  O(n²) 
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>lastSeen(32,-1);

        for (int i=n-1; i>=0; i--)
        {
            for (int b=0; b<32; b++)
            {
                if (nums[i] & (1<<b))
                {
                    lastSeen[b] = i;
                }
            }

            int farthest = i;
            for (int b=0; b<32; b++)
            {
                if (lastSeen[b] != -1)
                {
                    farthest = max(farthest,lastSeen[b]);
                }
            }
            ans[i] = farthest - i + 1;
        }
        return ans;
    }
};

//Time: O(32 * n) = O(n) (constant factor of 32 is negligible)
//Space: O(32 + n) = O(n)
