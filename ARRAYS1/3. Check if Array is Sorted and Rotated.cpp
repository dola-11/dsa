class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]>(nums[(i+1)%nums.size()]))     // Compare the current element with the next (using modulo for wraparound)
            count ++;
        }
        return count <= 1;
    }
};

//TC - O(n)
//SC - O(1)
