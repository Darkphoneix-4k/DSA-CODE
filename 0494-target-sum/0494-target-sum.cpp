class Solution {
public:
int  n ;
int total ;
vector <vector <int>> dp ;
  int solve (vector<int>& nums, int target  , int sum , int i ){
    if (i == n ){
        return sum == target ;
    }
    int idx = sum + total ;
    if (dp[idx][i] != -1){
        return dp[idx][i];
    }

    int add = solve (nums , target , sum + nums[i] , i+1);
    int sub = solve (nums , target , sum - nums[i] , i+1);
    return dp[idx][i] = add+sub ;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
      n = nums.size();
       total = accumulate (nums.begin(), nums.end(), 0);
      dp.assign (2*total + 1 , vector <int> (n+1 , -1));
      return solve (nums , target , 0 , 0);
    }
};