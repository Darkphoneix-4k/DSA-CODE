class Solution {
public:
int m ;
vector <vector<int>> dp ;

   bool solve (vector<int>& nums , int n , int i){
    if (i >= m || n < 0){
        return 0 ;
    }
    if (n == 0){
        return true ;
    }
    if (dp [n][i] != -1){
        return dp[n][i];
    }
    bool take = solve (nums , n - nums[i] , i+1);
    bool skip = solve (nums , n , i+1);
    return dp [n][i]= (take || skip) ;
   }

    bool canPartition(vector<int>& nums) {
        m = nums.size();
      
        int x = accumulate (nums.begin() , nums.end() , 0);
        if (x % 2 != 0){
            return false ;
        }
        int n = x/2;
         dp.assign ( n+1 , vector <int> (m+1 , -1));
        return solve (nums , n , 0);
    }
};