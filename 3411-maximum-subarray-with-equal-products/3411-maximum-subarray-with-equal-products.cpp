class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            __int128 prod = 1;
            __int128 l = 1;
            int g = 0;

            for (int j = i; j < n; j++) {

                prod *= nums[j];

                g = gcd(g, nums[j]);

                l = l / gcd((long long)l, (long long)nums[j])
                    * nums[j];

                if (prod == g * l) {
                    maxi = max(maxi, j - i + 1);
                }

                if (prod > g * l) {
                    break;
                }
            }
        }

        return maxi;
    }
};