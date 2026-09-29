class Solution {
public:
    int m, n;
    int memo[100][100][201];

    bool dfs(vector<vector<char>>& grid, int r, int c,
             int balance) {
        if (balance < 0) {
            return false;
        }
        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }
        if (memo[r][c][balance] != -1)
            return memo[r][c][balance];

        bool down = false;
        bool right = false;
        if (r + 1 < m) {

            if (grid[r + 1][c] == '(')
                down = dfs(grid, r + 1, c, balance + 1);
            else
                down = dfs(grid, r + 1, c, balance - 1);
        }
        if (c + 1 < n) {
           if (grid[r ][c+1] == '(')
                right = dfs(grid, r, c+1, balance + 1);
            else
                right = dfs(grid, r , c+1, balance - 1);
        }
        return memo[r][c][balance] =(down || right);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        if ((m + n -1 )% 2 != 0){
            return false ;
        }
        if (grid[0][0] == ')'){
            return false;
        }
       memset(memo, -1, sizeof(memo));

        return dfs(grid, 0, 0 , 1);
    }
};