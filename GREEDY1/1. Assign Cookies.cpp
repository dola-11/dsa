class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int child = 0; // Pointer for g
        int cookie = 0; // Pointer for s

        while(child < g.size() && cookie < s.size()) 
        {
            if(g[child] <= s[cookie])
            {
                child++;  // we can satisfy this child
            }
            cookie++;
        }
        return child;     // i children satisfied
    }
};

//TC : O(nlogn + nlogm + m)
//SC : O(1)
