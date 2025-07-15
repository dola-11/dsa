class Solution{
    public:
        vector<vector<int>> primeFactors(vector<int>& queries)
        {
            //your code goes here
            vector<int>spf(10001);
            for (int i=0; i<10001; i++)
            {
                spf[i] = i;
            }

            for(int i=2; i*i<10001; i++)
            {
                if(spf[i] == i)
                {
                    for(int j=i*i; j<10001; j+=i)
                    {
                        if(spf[j] == j)
                        {
                            spf[j] = i;
                        }
                    }
                }
            }

            vector<vector<int>>ans(queries.size());
            for(int i=0; i<queries.size(); i++)
            {
                int n = queries[i];

                while(n != 1)
                {
                    ans[i].push_back(spf[n]);
                    n = n/spf[n];
                }
            }

            return ans;
        }
};

| Operation         | Complexity            |
| ------------------| --------------------- |
| SPF Preprocessing | O(N log log N)        |
| Each Query        | O(log n) per query    |
| Space             | O(N) for SPF + output |
