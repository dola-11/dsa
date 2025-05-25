class Solution {
  public:
    void backtrack(int row, int column, vector<vector<int>> &maze, vector<string> &result, string &currentPath, vector<vector<int>>&visited)
    {
        int n = maze.size();
        if (row == n-1 && column == n-1)
        {
            result.push_back(currentPath);
            return;
        }
        
        int dr[4] = {-1, 0, 1, 0}; // U, L, D, R
        int dc[4] = {0, -1, 0, 1};
        char dir[4] = {'U', 'L', 'D', 'R'};
        
        visited[row][column] = 1;
        
        for (int i=0; i<4; i++)
        {
            int newrow = row + dr[i];
            int newcol = column + dc[i];
            
            if (newrow >=0 && newcol >=0 && newrow <n && newcol <n && maze[newrow][newcol] == 1 && visited[newrow][newcol] == 0)
            {
                currentPath.push_back(dir[i]);
                backtrack(newrow,newcol,maze,result,currentPath,visited);
                currentPath.pop_back();
            }
        }
        
        visited[row][column] = 0;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) 
    {
        // code here
        int n = maze.size();
        vector<string>result;
        
        if (maze[n - 1][n - 1] == 0 || maze[0][0] == 0) return result;
        
        string currentPath = "";
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        backtrack(0,0,maze,result,currentPath,visited);
        
        sort(result.begin(),result.end());
        return result;
    }
};

//TC : O(4^(n²)
//SC : O(n²)
