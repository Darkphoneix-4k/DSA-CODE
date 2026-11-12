
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int maxi = 1;

        for (int r = 0; r < n-1; r++) {
            if (nums[r+1] >= nums[r]) {
                l = r+1;
            }
            maxi = max(maxi, r-l+2);
        }

        l = 0;
        int maxi1 = 1;

        for (int r = 0; r < n-1; r++) {
            if (nums[r+1] <= nums[r]) {
                l = r+1;
            }
            maxi1 = max(maxi1, r-l+2);
        }

        return max(maxi, maxi1);
    }
};
