class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int r, int c) {

        if (board[r][c] != 'O')
            return;
        else{
            board[r][c] = '#';
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                dfs(board, nr, nc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        // Top and bottom rows
        for (int j = 0; j < n; j++) {

            if (board[0][j] == 'O')
                dfs(board, 0, j);

            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        // Left and right columns
        for (int i = 0; i < m; i++) {

            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        // Convert remaining O → X
        // Restore # → O
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};