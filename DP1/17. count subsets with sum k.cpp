//Recursive

class Solution {
  public:
    int countFunc(vector<int> & arr, int target, int index)
    {
        if (target == 0) return 1;
        if (index == 0) return arr[0] == target;
        
        int notTake = countFunc(arr,target,index-1);
        int take = 0;
        if (arr[index]<=target)
        {
            take = countFunc(arr, target-arr[index], index-1);
        }
        return take + notTake;
    }
    int perfectSum(vector<int>& arr, int target) 
    {
        int n = arr.size();
        return countFunc(arr,target,n-1);
    }
};

//SC : O(n)
//TC : O(2ⁿ)
