//brute force using a set datastructure -> nlogn + n?

//optimal - 2 pointers?
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        // set<int> withoutDup;
        // int lenNums = nums.size();
        // for (int i=0; i < lenNums;i++)
        // {
        //     withoutDup.insert(nums[i]);
        // }
        // return withoutDup.size();
        if (nums.empty())
        {
            return 0;
        }
        int i = 0;
        for (int j=1; j<nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};

//TC : O(n)
//SC : O(1)
