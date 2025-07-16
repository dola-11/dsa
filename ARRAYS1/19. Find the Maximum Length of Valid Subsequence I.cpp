class Solution {
public:
    int maximumLength(vector<int>& nums) 
    {
        int result = 0;
        vector<vector<int>> remainders = {{0,0},{0,1},{1,0},{1,1}};

        for (auto it:remainders)
        {
            int cnt = 0;
            for(int num: nums)
            {
                if(num % 2 == it[cnt%2])
                {
                    cnt++;
                }
            }
            result = max(result,cnt);
        }
        return result;
    }
};

//TC : O(4 × n) → O(n)
//SC : O(1)
