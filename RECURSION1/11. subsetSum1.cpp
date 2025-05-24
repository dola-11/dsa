class Solution {
  public:
    void subsetSums(int index, int currSum, vector<int>&arr, vector<int>&result)
    {
        if (index>=arr.size())
        {
            result.push_back(currSum);
            return;
        }
        
        subsetSums(index+1, currSum + arr[index], arr,result);
        subsetSums(index+1,currSum,arr,result);
    }
    
    vector<int> subsetSums(vector<int>& arr) 
    {
        // code here
        vector<int> result;
        subsetSums(0,0,arr,result);
        return result;
    }
};

//TC : O(2^n)
//SC : O(2^n + n)
