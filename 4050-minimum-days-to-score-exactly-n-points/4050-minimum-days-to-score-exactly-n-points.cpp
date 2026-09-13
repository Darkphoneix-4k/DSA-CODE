class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        dp[0] = -1;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; (j * (j + 1)) / 2 <= i; j++) {

                int points = j * (j + 1) / 2;

                dp[i] = min(dp[i],
                            dp[i - points] + j + 1);
            }
        }

        return dp[n];
    }

    int minDays(int n) {
        dp.assign(n + 1, INT_MAX);
        return solve(n);
    }
};