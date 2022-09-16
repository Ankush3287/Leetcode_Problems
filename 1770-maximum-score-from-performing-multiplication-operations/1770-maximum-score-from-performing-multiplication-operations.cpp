class Solution {
    public:
    int f(vector<int>&a,vector<int>& b,int i,int j,vector<vector<int>>&dp){
        int m=b.size();
        int n=a.size();
        if(j==m){
            return 0;
        }
        if(dp[i][j]!=INT_MIN)   return dp[i][j];
        int left=a[i]*b[j]+f(a,b,i+1,j+1,dp);
        int right=a[n-1-j+i]*b[j]+f(a,b,i,j+1,dp);
        return dp[i][j]= max(left,right);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m=multipliers.size();
        vector<vector<int>>dp(m,vector<int>(m,INT_MIN));
        return f(nums,multipliers,0,0,dp);
        
        // return dp[m-1][m-1];
    }
};