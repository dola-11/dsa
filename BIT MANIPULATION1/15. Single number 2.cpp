//3 methods from worst to best . (4th - hashmap -> worst)

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans = 0;
        int n = nums.size();
        for(int bitIndex = 0; bitIndex<=31; bitIndex++)
        {
            int count = 0;
            for(int i=0; i<n; i++)
            {
                if(nums[i] & (1<<bitIndex))
                {
                    count++;
                }
            }
            if (count%3 == 1)
            {
                ans = ans | (1<<bitIndex);
            }
        }
        return ans;
    }
};

//TC : O(32N)
//SC : O(1)


class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=1; i<n; i+=3)
        {
            if (nums[i] != nums[i-1])
            {
                return nums[i-1];
            }
        }
        return nums[n-1];
    }
};

//TC : NlogN + N/3
//SC : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ones = 0;
        int twos = 0;
        int n = nums.size();

        for(int i=0; i<n; i++)
        {
            ones = (ones^nums[i]) & ~twos;
            twos = (twos^nums[i]) & ~ones;
        }
        return ones;
    }
};

//TC : O(N)
//SC : O(1)
