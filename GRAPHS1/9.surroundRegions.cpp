//dfs slution

class Solution {
public:
    void dfs(int i,int j, vector<vector<char>>& finalBoard, vector<vector<int>> &visited)
    {
        int m = finalBoard.size();
        int n = finalBoard[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || finalBoard[i][j] != 'O')
        return;

        visited[i][j] = 1;

        dfs(i+1,j,finalBoard,visited);
        dfs(i-1,j,finalBoard,visited);
        dfs(i,j+1,finalBoard,visited);
        dfs(i,j-1,finalBoard,visited);
    }


    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        if (m==0) return;
        int n = board[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));
        for (int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (i == 0 || j == 0 || i == m-1 || j == n-1)
                {
                    if (board[i][j] == 'O')
                    {
                        dfs(i,j,board,visited);
                    }
                }
            }
        }
        for (int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (board[i][j] == 'O' and !visited[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


//TC : O(m*n)
//SC : O(m*n)


//bfs version
class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        if (m==0) return;
        int n = board[0].size();

        queue<pair<int,int>> q;

        //Enqueuing border 'O's
        for (int i=0; i<m; i++)
        {
            if (board[i][0] == 'O') q.push({i,0});
            if (board[i][n-1] == 'O') q.push({i,n-1});
        }

        for (int j=0; j<n; j++)
        {
            if (board[0][j] == 'O') q.push({0,j});
            if (board[m-1][j] == 'O') q.push({m-1,j});
        }

        while(!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();

            if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') continue;
            board[i][j] = 'S';

            q.push({i+1,j});
            q.push({i-1,j});
            q.push({i,j+1});
            q.push({i,j-1});

            for (int i = 0; i < m; i++) 
            {
                for (int j = 0; j < n; j++) 
                {
                    if (board[i][j] == 'O') board[i][j] = 'X';
                    if (board[i][j] == 'S') board[i][j] = 'O';
                }
            }
        }
    }
};

//TC : O(m*n)
//SC : O(m*n)
