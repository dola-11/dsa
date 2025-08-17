//brute force:

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans;
        vector<int>pos;
        vector<int>neg;
        
        for(int i=0; i<n; i++)
        {
            if (nums[i]>0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }

        int j = 0;
        int k = 0;
        for (int i=0; i<n; i++)
        {
            if (i%2 == 0)
            {
                ans.push_back(pos[j]);
                j++;
            }
            else
            {
                ans.push_back(neg[k]);
                k++;
            }
        }

        return ans;
    }
};

//TC : O(n) + O(n) = O(n)
//SC : O(3N) = O(N)


//optimal approach
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans(n,0);
        int neg = 1;
        int pos = 0;

        for (int i=0; i<n; i++)
        {
            if(nums[i]<0)
            {
                ans[neg] = nums[i];
                neg += 2;
            }
            else
            {
                ans[pos] = nums[i];
                pos += 2;
            }
        }
        return ans;
    }
};

//TC : O(n)
//SC : O(N)
