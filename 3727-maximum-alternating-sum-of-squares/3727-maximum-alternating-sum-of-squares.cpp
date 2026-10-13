class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

       for (int i =0; i <n ; i++ ){
          nums[i] = abs(nums[i]);
       }
       sort (nums.begin(), nums.end(), greater <int>());
       long long sum = 0;
       int l = 0;
       int r = n-1 ;
       for (int i = 0; i < n ; i++) {
           if (i % 2 == 0){
            sum += (nums[l]*nums[l]);
            l++;
           }
           else {
            sum -= (nums[r]*nums[r]);
            r--;
           }
       }
       return sum;
    }
};