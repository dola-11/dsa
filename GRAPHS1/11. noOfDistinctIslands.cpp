//dfs solution

class Solution {
  public:
    void dfs (int i,int j,vector<vector<int>>& grid, vector<vector<int>>&visited, vector<pair<int,int>>&coordinates,int rowbase, int colbase)
    {
        int m = grid.size();
        int n = grid[0].size();
    
        
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j] != 1 || visited[i][j] == 1) return;
        
        visited[i][j] = 1;
        coordinates.push_back({i-rowbase,j-colbase});
        
        dfs(i+1,j,grid,visited,coordinates,rowbase,colbase);
        dfs(i,j+1,grid,visited,coordinates,rowbase,colbase);
        dfs(i-1,j,grid,visited,coordinates,rowbase,colbase);
        dfs(i,j-1,grid,visited,coordinates,rowbase,colbase);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        // code here
        int m = grid.size();
        if (m==0) return 0;
        int n = grid[0].size();
        
        vector<vector<int>>visited(m,vector<int>(n,0));
        set <vector<pair<int,int>>> st;
        
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    vector<pair<int,int>> coordinates;
                    dfs(i,j,grid,visited,coordinates,i,j);
                    st.insert(coordinates);
                }
            }
        }
        return st.size();
    }
};

// SC : O(m*n)
//TC : O(m*n*log(m*n)+(m*n*4))

//bfs
class Solution {
  public:
    void bfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&visited, vector<pair<int,int>>&coordinates,int rowbase, int colbase)
    {
        int m = grid.size();
        if (m==0) return;
        int n = grid[0].size();
        
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j] = 1;
        coordinates.push_back({0, 0});
        
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for (auto dir : directions)
            {
                int delrow = dir.first;
                int delcol = dir.second;
                int nrow = row + delrow;
                int ncol = col + delcol;
                
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0)
                {
                     q.push({nrow,ncol});
                     visited[nrow][ncol] = 1;
                     
                     coordinates.push_back({nrow - rowbase, ncol - colbase});
                }
            }
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        // code here
        int m = grid.size();
        if (m==0) return 0;
        int n = grid[0].size();
        
        vector<vector<int>>visited(m,vector<int>(n,0));
        set<vector<pair<int,int>>> st;
        
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    vector<pair<int,int>> coordinates;
                    bfs(i,j,grid,visited,coordinates,i,j);
                    st.insert(coordinates);
                }
            }
        }
        return st.size();
    }
};

//TC : O(m*n*log(m*n)+(m*n*4))
//SC : O(m * n)
