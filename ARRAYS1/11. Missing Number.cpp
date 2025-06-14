//Method 1:

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int reqSum = 0;
        for (int i=0; i<n; i++)
        {
            reqSum += nums[i];
        }
        return sum - reqSum;
    }
};

//Method 2:
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        //2nd solution using XOR
        int n = nums.size();
        int xorSum = 0;

        for (int i=0; i<= n; i++)
        {
            xorSum ^= i;
        }

        for (int num: nums)
        {
            xorSum ^= num;
        }

        return xorSum;
    }
};

//TC:O(N)
//SC:O(1)
