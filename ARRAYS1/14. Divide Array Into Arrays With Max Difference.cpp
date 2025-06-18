class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());

        for (int i=0; i<n; i+=3)
        {
            if(nums[i+2] - nums[i] > k)
            {
                return {};
            }
            result.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return result;
    }
};

//Time complexity: O(N⋅logN)
//Space complexity: O(logN) -> In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort, and Insertion Sort, with a worst-case space complexity of O(logN)
