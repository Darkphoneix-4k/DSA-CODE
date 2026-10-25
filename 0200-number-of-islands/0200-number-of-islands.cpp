class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{0,-1},{-1,0}};
    void dfs(int i,int j,vector<vector<int>>&vis,int r,int c,vector<vector<char>>&grid){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dir[k][0];
            int nc=j+dir[k][1];
            if(nr<r&&nr>=0&&nc<c&&nc>=0&&vis[nr][nc]==0&&grid[nr][nc]=='1'){
                dfs(nr,nc,vis,r,c,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,vis,r,c,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};