class Solution {
    public:
    int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int n=triangle.size();
        if(i==(n-1))    return triangle[i][j];
        if(dp[i][j]!=-1)    return dp[i][j];
        int down=f(i+1,j,triangle,dp);
        int diagonal=f(i+1,j+1,triangle,dp);
        return dp[i][j]=triangle[i][j]+min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,triangle,dp);
    }
};