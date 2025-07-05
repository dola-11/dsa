class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) 
    {
        // Your code here
        int n = start.size();
        vector<pair<int,int>>intervals;
        
        for(int i=0; i<n; i++)
        {
            intervals.push_back({end[i],start[i]});
        }
        
        sort(intervals.begin(),intervals.end());
        
        int count = 1;
        int freeTime = intervals[0].first;
        
        for(int i=1; i<n; i++)
        {
            auto element = intervals[i];
            int start = element.second;
            
            if(start>freeTime)
            {
                count += 1;
                freeTime = element.first;
            }
        }
        return count;
    }
};

//TC : O(n log n)
//SC : 	O(n)
