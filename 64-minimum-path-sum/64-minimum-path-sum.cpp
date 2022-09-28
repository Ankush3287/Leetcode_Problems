class Solution {
    public:
    int f(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)    return grid[i][j];
        if(i<0 || j<0)  return INT_MAX;
        if(dp[i][j]!=-1)    return dp[i][j];
        int up=f(grid,i-1,j,dp);
        int left=f(grid,i,j-1,dp);
        return dp[i][j]=grid[i][j]+min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i=grid.size();
        int j=grid[0].size();
        vector<vector<int>>dp(i,vector<int>(j,-1));
        return f(grid,i-1,j-1,dp);
        
    }
};