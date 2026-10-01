class Solution {
public:
int m; 
int n ;
 void dfs (vector<vector<char>>& grid , int r , int c ){
    
    if (r < 0 || r >=m || c <0 || c >=n){
        return ;
    }
    if (grid[r][c]=='0'){
        return ;
    }
    grid[r][c]='0';
    if (r < m){
        dfs (grid , r+1 , c);
    }
    if (r < m){
        dfs (grid , r-1 , c);
    }
    if (c < n){
        dfs (grid , r , c+1);
    }
    if (c < n){
        dfs (grid , r , c-1);
    }
 }

    int numIslands(vector<vector<char>>& grid) {
         m = grid.size();
         n = grid[0].size();
         int total=0;
         for (int i = 0; i < m ; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]=='1'){
                  total++;


                  dfs (grid , i , j);
                }
            
         }

         }
         return total ;

    }
};