class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);
        long long total = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (k >= total) return 0;

       
        long long low = 0, high = mx;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long cost = 0;

            for (long long d : diff) {
                cost += max(0LL, d - mid);
            }

            if (cost <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long level = low;
        long long used = 0;

      
        for (int i = 0; i < n; i++) {
            if (diff[i] > level) {
                used += diff[i] - level;
                diff[i] = level;
            }
        }


        long long remaining = k - used;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] == level) {
                diff[i]--;
                remaining--;
            }
        }

        long long ans = 0;

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};