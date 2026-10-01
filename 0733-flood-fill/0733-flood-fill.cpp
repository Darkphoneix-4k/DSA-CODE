class Solution {
public:
    int m;
    int n;
    int original;
    int newColor;

    void dfs(vector<vector<int>>& image, int r, int c) {

    
        if (r < 0 || r >= m || c < 0 || c >= n) {
            return;
        }

        if (image[r][c] != original) {
            return;
        }

     
        image[r][c] = newColor;

      
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            dfs(image, nr, nc);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        m = image.size();
        n = image[0].size();

        original = image[sr][sc];
        newColor = color;

     
        if (original == newColor) {
            return image;
        }

        dfs(image, sr, sc);

        return image;
    }
};