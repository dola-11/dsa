//1st solution

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        int n = nums.size();
        int j = 0;

        while(j<n)
        {
            for (int i=0; i<n; i++)
            {
                if (nums[i] == original)
                {
                    original = original*2;
                }
            }
            j++;
        }
        return original;
    }
};

//TC = O(n^2)


//2nd soln
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        sort(nums.begin(), nums.end());
        for (int num:nums)
        {
            if (num == original)
            {
                original = original*2;
            }
        }
        return original;
    }
};

//TC : O(nlogn)
//SC : O(logn)

//3rd soln
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(original)) 
        {
            original *= 2;
        }
        return original;
    }
};

//TC : O(n)
//SC : O(n)
