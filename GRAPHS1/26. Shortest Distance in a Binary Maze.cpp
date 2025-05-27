//using bfs because edge weights were unit

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        //if start or end is blocked
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        //directions vector : no of possible directions: 8
        vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
        
        //queue for bfs: stores coordinates and current path length.
        queue<tuple<int,int,int>> q;
        q.push({0,0,1});
        grid[0][0] = 1;

        while(!q.empty())
        {
            auto [x,y,steps] = q.front();
            q.pop();

            if (x == n-1 && y == n-1) return steps;

            for (auto [dx,dy] : directions)
            {
                int nx = x + dx;
                int ny = y + dy;

                if (nx>=0 && ny >= 0 && nx<n && ny <n && grid[nx][ny] == 0)
                {
                    q.push({nx,ny,steps+1});
                    grid[nx][ny] = 1;
                }
            }
        }
        return -1;
    }
};


//TC : O(n^2)
//SC : O(n^2)

//same thing as above using a visited grid would be :
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        // If start or end is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

        // All 8 possible directions
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, 1}, {0, -1},
            {1, -1}, {1, 0}, {1, 1}
        };

        // Visited matrix
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        // BFS queue: (x, y, steps so far)
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});

        while (!q.empty()) {
            auto [x, y, steps] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1)
                return steps;

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0 && !visited[nx][ny]) 
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, steps + 1});
                }
            }
        }

        return -1; // No path found
    }
};

//TC : O(n^2)
//SC : O(n^2) + O(n^2)

//Using Dijkstra's algorithm
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
        return -1;

        queue<pair<int,pair<int,int>>> q;

        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0] = 1;

        vector<pair<int,int>> directions = {{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
        q.push({1,{0,0}});

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int currDist = node.first;
            int row = node.second.first;
            int column = node.second.second;

            if (row == n - 1 && column == n - 1)
                return currDist;

            for (auto [dx,dy]:directions)
            {
                int newrow = row + dx;
                int newcol = column + dy;

                if (newrow >= 0 && newcol >= 0 && newrow <n && newcol < n && grid[newrow][newcol] == 0 && dist[newrow][newcol] > 1 + currDist)
                {
                    dist[newrow][newcol] = 1 + currDist;

                    q.push({1+ currDist, {newrow,newcol}});
                }

            }
        }
        return -1;
    }
};

//TC : O(n^2)
//SC : O(n^2) + O(n²)
