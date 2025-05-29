//Iterative 

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if (nums[mid] == target) return mid;

            else if (nums[mid] < target)
            {
                low = mid+1;
            } 
            else 
            {
                high = mid-1;
            }
        }
        return -1;
    }
};

//TC : O(log n)
//SC : O(1)

//Recursive

class Solution {
public:
    int binarySearch(vector<int> &nums, int low, int  high, int target)
    {
        if (low > high) return -1;

        int mid = low + (high-low)/2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target)
        {
            return binarySearch(nums,mid+1,high,target);
        }
        return binarySearch(nums,low,mid-1,target);
    }

    int search(vector<int>& nums, int target) 
    {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};

//TC : O(log n)
//SC : O(log n)
