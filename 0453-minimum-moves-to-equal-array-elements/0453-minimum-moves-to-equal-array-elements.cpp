class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int x = accumulate(nums.begin() , nums.end(), 0);
        int y = *min_element (nums.begin(), nums.end());
        return x - (n * y);

    }
};