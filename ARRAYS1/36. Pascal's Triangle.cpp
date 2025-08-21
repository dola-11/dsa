//two approaches:
class Solution {
public:
    vector<int>generateRow(int row)
    {
        long long ans = 1;
        vector<int>ansRow;
        ansRow.push_back(1);
        for (int col = 1; col < row; col++)
        {
            ans = ans * (row-col);
            ans = ans/col;

            ansRow.push_back(ans);
        }
        return ansRow;
    }
    
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>>ans;
        for (int i=1; i<=numRows; i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

//Each row is generated independently using the nCr formula.
//nCr = nCr-1 * (n-r)/r
//Time per row: O(n)
//Space per row: O(n)
//generating all rows : O(n^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> triangle(numRows);
        for (int i = 0; i < numRows; i++)
        {
            triangle[i].resize(i + 1);  
            triangle[i][0] = triangle[i][i] = 1;  

            for (int j = 1; j < i; j++)  
            {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }

        return triangle;
    }
};

//Builds Pascal’s Triangle row by row using the recursive relation:
//nCr = n-1Cr-1 + n-1Cr
//Time: O(n^2)
//Space : O(n^2)
