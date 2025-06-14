class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = 1;

        for (int i=1; i<n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            } 
        }
        return len;
    }
};

//To get the index (like 0, 1, 2, etc.) from an iterator, you subtract temp.begin() from that iterator:

| Complexity | Value                             |
| ---------- | --------------------------------- |
| Time       | O(n log n) (due to `lower_bound`) |
| Space      | O(n) (for `temp`)                 |
