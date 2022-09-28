class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>prev(m,INT_MAX);
        for(int i=0;i<n;i++){
            vector<int>curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    curr[j]=grid[i][j];
                    continue;
                }
                int up=prev[j];
                int left=INT_MAX;
                
                if(j>0) left=curr[j-1];
                curr[j]=grid[i][j]+min(up,left);
            }
            prev=curr;
        }
        return prev[m-1];
        
    }
};