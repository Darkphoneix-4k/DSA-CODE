class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxreach =  0;
        int count = 0;
        int check = 0;
        for (int i = 0; i < n -1; i++ ){
            maxreach = max(maxreach , i + nums[i]);
            if (i == check ){
                count++;
                check = maxreach ;
            }
        }
        return count ;
    }
};