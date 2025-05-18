//dfs solution
class Solution {
public:
    void dfs(int i,int j, vector<vector<int>>& grid, vector<vector<int>> &visited)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i<0 || j<0 || i>=m || j>=n || grid[i][j]!=1 || visited[i][j]) return;

        visited[i][j] = 1;

        dfs(i+1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j-1,grid,visited);
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        if(m == 0)return 0;
        int n = grid[0].size();
        int enclaveCount = 0;

        vector<vector<int>>visited(m,vector<int>(n,0));

        for (int i=0; i<m; i++)
        {
            if (grid[i][0] == 1)
            {
                dfs(i,0,grid,visited);
            }
            if (grid[i][n-1] == 1)
            {
                dfs(i,n-1,grid,visited);
            }
        }

        for (int j=0; j<n; j++)
        {
            if (grid[0][j] == 1)
            {
                dfs(0,j,grid,visited);
            }
            if (grid[m-1][j] == 1)
            {
                dfs(m-1,j,grid,visited);
            }
        }

        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n;j++)
            {
                if (grid[i][j] == 1 and !visited[i][j])
                {
                    enclaveCount++;
                }
            }
        }
        return enclaveCount;
    }
};

//TC : O(m × n)
//SC : O(m × n)

//bfs traversal
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if (grid[i][n - 1] == 1) {
                q.push({i, n - 1});
                visited[i][n - 1] = 1;
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                visited[0][j] = 1;
            }
            if (grid[m - 1][j] == 1) {
                q.push({m - 1, j});
                visited[m - 1][j] = 1;
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n && 
                    grid[ni][nj] == 1 && visited[ni][nj] == 0) {
                    visited[ni][nj] = 1;
                    q.push({ni, nj});
                }
            }
        }

        int enclaveCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    enclaveCount++;
                }
            }
        }

        return enclaveCount;
    }
};

//TC : O(m × n)
//SC : O(m × n)
