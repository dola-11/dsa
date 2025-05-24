class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i=0; i<9; i++)
        {
            if (board[i][col] == c) return false;

            if (board[row][i] == c) return false;

            if (board[ 3 * (row/3) + (i/3)][ 3 * (col/3) + (i%3)] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i=0; i<board.size(); i++)
        {
            for (int j=0; j<board.size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char c = '1'; c<= '9'; c++)
                    {
                        if (isValid(board,i,j,c))
                        {
                            //if this check is valid we update
                            board[i][j] = c;

                            //recursion for further down
                            if (solve(board) == true) return true;

                            //if not backtrack
                            board[i][j] = '.';
                        }
                    }
                    //if not valid return false
                    return false;
                }
            }
        }
        //if all iterations are complete return true;
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};

//TC : Worst-case: O(9^(81))
//SC : O(81) for recursion stack in worst case. O(1) extra space (since the board is 9x9, constant size)
