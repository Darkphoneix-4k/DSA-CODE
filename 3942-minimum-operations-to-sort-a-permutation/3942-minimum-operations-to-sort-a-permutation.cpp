class Solution {
public:
    bool checkRight(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n])
                cnt++;
        }

        return cnt <= 1;
    }
    bool checkLeft(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[(i + 1) % n])
                cnt++;
        }

        return cnt <= 1;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i = min_element (nums.begin() , nums.end())- nums.begin();
        if (checkRight(nums)) {
            return min (i , n -i + 2);
        } else if (checkLeft(nums)) {
            return min ( i+2 , n -i);
        }
         else {
            return -1;
        }
    }
};