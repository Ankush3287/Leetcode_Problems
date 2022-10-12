//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int f(int ind,int W,int val[],int wt[],vector<vector<int>>&dp){
        if(ind ==0){
              return val[0]*(W/wt[0]);
        }
        if(dp[ind][W]!=-1)  return dp[ind][W];
        int pick=-1e9;
        int notPick=f(ind-1,W,val,wt,dp );
        if(wt[ind]<=W)  pick=val[ind]+f(ind,W-wt[ind],val,wt,dp);
        return dp[ind][W]=max(pick,notPick);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,0));
        vector<int>prev(W+1),curr(W+1,0);
        for(int i=0;i<=W;i++){
            prev[i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int pick=0;
                int notPick=prev[j];
                if(wt[i]<=j)  pick=val[i]+curr[j-wt[i]];
                curr[j]=max(pick,notPick);
            }
            prev=curr;
        }
        return prev[W];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends