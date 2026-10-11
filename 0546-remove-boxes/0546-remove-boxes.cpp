class Solution {
public:
    int dp[100][100][100];

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;

        if (dp[l][r][k] != -1)
            return dp[l][r][k];

        int origL = l, origK = k;

        while (l < r && boxes[l] == boxes[l + 1]) {
            l++;
            k++;
        }

        int ans = (k + 1) * (k + 1) + solve(boxes, l + 1, r, 0);

        for (int m = l + 1; m <= r; m++) {
            if (boxes[m] == boxes[l]) {
                ans = max(ans,
                    solve(boxes, l + 1, m - 1, 0) +
                    solve(boxes, m, r, k + 1));
            }
        }

        return dp[origL][r][origK] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));

        // Compress consecutive boxes of the same color
        vector<int> compressed;
        for (int i = 0; i < boxes.size(); i++) {
            if (i == 0 || boxes[i] != boxes[i - 1])
                compressed.push_back(boxes[i]);
        }
        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};
