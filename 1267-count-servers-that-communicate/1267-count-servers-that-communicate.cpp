class Solution {
public:
int m ;
int n ;
    void dfs(int i, int j, vector<vector<int>>& grid, int& count) {
        if (grid[i][j] == 0)
            return;

        grid[i][j] = 0;
        count++;

        
        for (int col = 0; col < n; col++) {
            if (grid[i][col] == 1) {
                dfs(i, col, grid, count);
            }
        }

        for (int row = 0; row < m; row++) {
            if (grid[row][j] == 1) {
                dfs(row, j, grid, count);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
            m = grid.size();
            n = grid[0].size();

        int ans = 0;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(i, j, grid, count);

                    if (count > 1) {
                        ans += count;
                    }
                }
            }
        }
        return ans ;
    }
};