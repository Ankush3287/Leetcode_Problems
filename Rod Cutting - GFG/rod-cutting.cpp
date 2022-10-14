//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    int f(int ind,int k,int price[],vector<vector<int>>&dp){
        if(ind ==0){
            return price[ind]*(k/1);
        }
        if(dp[ind][k]!=-1)  return dp[ind][k];
        int pick=-1e9;
        int notPick=0+f(ind -1,k,price,dp);
        if(ind+1<=k)    pick=price[ind]+f(ind,k-ind-1,price,dp);
        return dp[ind][k]=max(pick,notPick);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i=0;i<=n;i++){
            prev[i]=price[0]*i;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int notPick=prev[j];
                int pick=-1e9;
                if(i+1<=j)  pick=price[i]+curr[j-i-1];
                curr[j]=max(pick,notPick);
            }
            prev=curr;
        }
        return prev[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends