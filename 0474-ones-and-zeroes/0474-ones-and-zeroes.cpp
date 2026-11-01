class Solution {
public:
int dp[605][101][101];
int  solve (int idx , vector<string>& strs, int m, int n){
    if (idx == strs.size()){
        return 0;
    }
    if (dp[idx][m][n] != -1)
            return dp[idx][m][n];

    int z = 0,o =0;
    for (char ch : strs[idx]){
        if (ch == '0'){
            z++;
        }
        else{
                o++;
            }
        }
    

int skip = solve (idx+1 , strs , m , n);
int take =0;
if (z <= m && o <= n){
     take = 1+ solve (idx +1 , strs , m-z, n-o);

}

return dp[idx][m][n]=max (take , skip );
}

    int findMaxForm(vector<string>& strs, int m, int n) {
       
        memset(dp, -1, sizeof(dp));

         int ans = solve ( 0,strs , m ,n);

        return ans ;
    }
};