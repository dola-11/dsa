class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n = nums.size();

        int j = 0;
        for(int i=0; i<n; i++)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                if (i != j)
                {
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
};

//O(n) time and O(1) extra space
