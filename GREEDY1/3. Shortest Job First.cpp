// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) 
    {
        // code here
        sort(bt.begin(), bt.end());
        long long time = 0;
        long long waitTime = 0;
        
        for(int i=0; i<bt.size(); i++)
        {
            waitTime += time;
            time += bt[i];
        }
        
        return waitTime/bt.size();
    }
};

//TC : O(N) + O(NlogN)
//SC : O(1)
