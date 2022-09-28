class Solution {
    public:
    int f(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>> &dp){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1)   return 0;
        if(i==0 && j==0)    return 1;
        if(i<0 || j<0)  return 0;
        if(dp[i][j]!=0) return dp[i][j];
        int up=f(obstacleGrid,i-1,j,dp);
        int left=f(obstacleGrid,i,j-1,dp);
        return dp[i][j]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i=obstacleGrid.size();
        int j=obstacleGrid[0].size();
        vector<vector<int>>dp(i,vector<int>(j,0));
        return f(obstacleGrid,i-1,j-1,dp);
    }
};