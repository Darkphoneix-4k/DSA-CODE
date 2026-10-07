class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& dungeon, int r, int c) {
        if (r == n - 1 && c == m - 1) {
            return max(1, 1 - dungeon[r][c]);
        }

        if (dp[r][c] != -1)
            return dp[r][c];

        int dr[] = {1, 0};
        int dc[] = {0, 1};

        int ans = INT_MAX;

        for (int i = 0; i < 2; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < n && nc < m) {
                int next = dfs(dungeon, nr, nc);
                int curr = max(1, next - dungeon[r][c]);

                ans = min(ans, curr);
            }
        }

        return dp[r][c] = ans;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();

        dp.assign(n, vector<int>(m, -1));

        return dfs(dungeon, 0, 0);
    }
};
