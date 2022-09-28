class Solution {
    public:
    int f(int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0)    return dp[i][j]=1;
        if(i<0)    return 0;
        if(j<0)    return 0;
        if(dp[i][j]!=0)    return dp[i][j];
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=up+left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,0);
        vector<int>temp(n,0);
        temp[0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)    continue;
                if(j==0)    temp[j]=dp[j];
                else
                temp[j]=temp[j-1]+dp[j];
            }
            dp=temp;
            
        }
        return dp[n-1];
    }
};