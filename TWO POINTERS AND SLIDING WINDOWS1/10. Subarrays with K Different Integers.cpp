class Solution {
public:
    int countRangeK(vector<int>&nums, int k)
    {
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int,int>freq;

        while(right < nums.size())
        {
            freq[nums[right]]++;
            while(freq.size()>k)
            {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0)
                {
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += right - left +1;
            right ++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return countRangeK(nums, k) - countRangeK(nums,k-1);
    }
};

//TC : O(n)
//SC : O(k)
