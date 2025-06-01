//if edge doesnt exist then -1
//code:

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) 
    {
        // Code here
        int n = dist.size();
        
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][j] == -1)
                {
                    dist[i][j] = 1e9;
                }
                if (i==j) dist[i][j] = 0;
            }
        }
        
        for (int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                   if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][j] == 1e9)
                {
                    dist[i][j] = -1;
                }
            }
        }
    }
};


//if edge doesnt exist is set to infinity
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) 
    {
        // Code here
        int n = dist.size();
        
        for (int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                   if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                        dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
                }
            }
        }
        
    }
};

//to detect negative weight cycles
for (int i=0; i<n; i++)
{
  if (dist[i][i] < 0)
  {
    ....
  }
}

//can be solved using separate cost matrix as well


//TC : O(n^3)
//SC : O(1) (in-place) or O(n^2) (with separate matrix) but recommended to say 0(n^2)
