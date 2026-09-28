class Solution {
public:
using ll =unsigned long long ;
ll  dp [101][101][101];
int n ;
ll power(ll base, ll exponent){
    if(exponent == 0)return 1;
    ll half = power(base, exponent / 2);
    ll ans =( half * half) % (1000000007);
    if(exponent % 2 ==1){
        ans = (ans * base) %1000000007;
    }
    return ans;
}

ll  solve (vector <int> &nums, int k , int i , int sum, int len){
    if (i == n){
        if (sum == k){
         ll  x = power(2, n - len);
         return x;
        } 
        return 0;  
    }
    if(sum > k)return 0;
    if (dp[i][sum][len]!= -1){
        return dp[i][sum][len];
    }
     ll  take = (solve (nums, k , i+1 ,sum+nums[i] , len+1)) %(1000000007);

     ll dt = (solve (nums , k , i+1 , sum , len))%(1000000007);
     return dp[i][sum][len]=(take + dt)%(1000000007);

}
    int sumOfPower(vector<int>& nums, int k) {
        n = nums.size();
        memset (dp , -1 , sizeof(dp));
        ll  ans = solve (nums , k , 0 , 0 , 0);
        return ans ;
    }
};