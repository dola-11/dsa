class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        auto gain = [](int p, int t)
        {
            return (double)(p+1)/(t+1) - (double)p/(double)t;
        };

        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto &c : classes)
        {
            int p = c[0];
            int t = c[1];
            pq.push({gain(p,t),{p,t}});
        }

        while(extraStudents--)
        {
            auto [g, pt] = pq.top();
            pq.pop();
            int p = pt.first;
            int t = pt.second;
            p++;
            t++;
            pq.push({gain(p,t),{p,t}});
        }

        double total = 0.0;
        while(!pq.empty())
        {
            auto [gain,pt] = pq.top();
            pq.pop();
            int p = pt.first;
            int t = pt.second;

            total += (double)p / t;
        }

        return total / classes.size();
    }
};

/*
TC : O((n + m) log n)
Building the priority queue (initial push)
You push each of the n = classes.size() classes once.
Each push into a heap costs O(log n).
So, initial build = O(n log n).

Distributing extraStudents
For each extra student (m = extraStudents), you pop and push once.
Each pop and push = O(log n).
So, distributing = O(m log n).

Final sum calculation
You pop each element once = O(n log n).


Space = O(n)
*/
