
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // dp[r] = number of subarrays ending at current index
        // whose product % k == r
        vector<long long> dp(k, 0);

        for (long long num : nums) {
            long long mod = num % k;

            vector<long long> newDp(k, 0);

            // Start a new subarray with only nums[i]
            newDp[mod]++;

            // Extend all previous subarrays
            for (long long r = 0; r < k; r++) {
                long long newR = (r * mod) % k;
                newDp[newR] += dp[r];
            }

            // Add current subarrays to answer
            for (long long r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};
































