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
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down=dp[i+1][j];
                int diagonal=dp[i+1][j+1];
                dp[i][j]=triangle[i][j]+min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};