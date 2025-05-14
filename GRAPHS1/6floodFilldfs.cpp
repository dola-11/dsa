class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldCol, int target)
    {
        int m = image.size();
        int n = image[0].size();

        if (sr<0 || sr>=m || sc<0 || sc>=n || image[sr][sc] != oldCol) return;

        image[sr][sc] = target;

        dfs(image,sr+1,sc,oldCol, target);
        dfs(image,sr-1,sc,oldCol, target);
        dfs(image,sr,sc+1,oldCol, target);
        dfs(image,sr,sc-1,oldCol, target);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if (image[sr][sc] == color) return image;
        else
        {
            int oldCol = image[sr][sc];
            dfs(image,sr,sc, oldCol, color);
        }
        return image;
    }
};
