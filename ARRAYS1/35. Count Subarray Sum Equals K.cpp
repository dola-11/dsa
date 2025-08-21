class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        map<int,int>prefixMap;      // maps: prefixSum -> how many times we've seen it
        prefixMap[0] = 1;           // one way to have sum 0 before we start (empty prefix)

        int n = nums.size();
        int sum = 0;
        int cnt = 0;

        for (int i=0; i<n; i++)
        {
            sum += nums[i];
            int req = sum - k;
            if (prefixMap.count(req))     //if such a prefix sum occurred before
            {
                cnt += prefixMap[req];    // add how many times it occurred, (each occurrence gives a valid subarray ending at i)
            }
            prefixMap[sum]+=1;            //record current prefix sum for future indices
        }
        return cnt;
    }
};

