class Solution {
public:
vector < vector <int >> dp ;
int solve (int amount, vector<int>& coins , int i){
    if (amount == 0){
        return 1 ;
    }
    if ( i == coins.size()){
        return 0 ;
    }

    if (dp[amount][i] != -1){
            return dp[amount][i];
    }

 int ways = 0;
    if (coins[i] <= amount){
     ways += solve (amount - coins[i], coins , i );
    }

    ways += solve (amount , coins , i+1);
    return dp[amount][i] = ways ;
}
    int change(int amount, vector<int>& coins) {
        dp.assign (amount + 1, vector<int>(coins.size() +1, -1) );
        int ans = solve (amount , coins , 0);
        return ans ;
    }
};