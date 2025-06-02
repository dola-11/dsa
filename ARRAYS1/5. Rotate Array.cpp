//if we have to rotate by just one position, for eg rotate left by one step then store the first in temporary, shift by one then enter the last value from temp

//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k%n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

//TC : O(n)
//SC : O(1)
