class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m = image.size();
        int n = image[0].size();
        int oldCol = image[sr][sc];
        if (oldCol == color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for (int i=0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc] == oldCol)
                {
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};

//SC : O(m*n)
//TC : O(m*n)
