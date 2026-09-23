class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return nums.size();

        int l = 0;
        int sum = 0;
        int maxLen = -1;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum > target && l <= r) {
                sum -= nums[l];
                l++;
            }

            if (sum == target) {
                maxLen = max(maxLen, r - l + 1);
            }
        }

        if (maxLen == -1)
            return -1;

        return nums.size() - maxLen;
    }
};
