class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a valid subarray
        // completely inside arr[0 ... i-1]
        vector<int> best(n + 1, INF);

        int ans = INF;
        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target && left <= right) {
                sum -= arr[left++];
            }

            // Current window [left, right] has sum == target
            if (sum == target) {
                int len = right - left + 1;

                // Combine current subarray with a previous
                // non-overlapping valid subarray.
                if (left > 0 && best[left] != INF) {
                    ans = min(ans, len + best[left]);
                }

                // Store the shortest valid subarray ending at/before right.
                best[right + 1] = min(best[right], len);
            } else {
                best[right + 1] = best[right];
            }
        }

        return ans == INF ? -1 : ans;
    }
};
