class Solution {
public:

    int n;
    int m;
    int count;

    int solve(vector<vector<int>>& forest,
              int sr, int sc,
              int tr, int tc) {

        vector<vector<int>> dist(n, vector<int>(m, -1));

        queue<pair<int, int>> q;

        q.push({sr, sc});
        dist[sr][sc] = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            if (r == tr && c == tc)
                return dist[r][c];

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= m)
                    continue;

                if (forest[nr][nc] == 0)
                    continue;

                if (dist[nr][nc] != -1)
                    continue;

                dist[nr][nc] = dist[r][c] + 1;

                q.push({nr, nc});
            }
        }

        return -1;
    }


    int cutOffTree(vector<vector<int>>& forest) {

        n = forest.size();
        m = forest[0].size();

        count = 0;

        vector<tuple<int, int, int>> trees;

     
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                if (forest[r][c] > 1) {
                    trees.push_back({
                        forest[r][c],
                        r,
                        c
                    });
                }
            }
        }

    
        sort(trees.begin(), trees.end());

  
        int cr = 0;
        int cc = 0;

        // Visit trees in increasing height
        for (auto [height, r, c] : trees) {

            int d = solve(
                forest,
                cr, cc,
                r, c
            );

            if (d == -1)
                return -1;

            count += d;

            cr = r;
            cc = c;
        }

        return count;
    }
};
