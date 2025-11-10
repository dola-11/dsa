class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        vector<int>s;
        int ops = 0;
        for (int num : nums)
        {
            while( !s.empty() && s.back() > num)
            {
                s.pop_back();
            }
            if (num == 0) continue;
            if (s.empty() || s.back() < num)
            {
                ops++;
                s.push_back(num);
            }
        }
        return ops;
    }
};

//Time Complexity: O(n) (each element pushed/popped at most once)
//Space Complexity: O(n) (for stack)
