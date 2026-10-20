class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevLast = -1;

            for (int start = 0; start < n && valid; start += k) {
                int descents = 0;
                int descentIndex = -1;

                for (int j = 0; j < k; j++) {
                    int curr = start + j;
                    int next = start + (j + 1) % k;

                    if (nums[curr] > nums[next]) {
                        descents++;
                        descentIndex = j;
                    }
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }

                int first, last;

                if (descents == 0) {
                    first = nums[start];
                    last = nums[start + k - 1];
                } else {
                    first = nums[start + (descentIndex + 1) % k];
                    last = nums[start + descentIndex];
                }

                if (prevLast != -1 && prevLast > first) {
                    valid = false;
                    break;
                }

                prevLast = last;
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};