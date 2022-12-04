//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod=1003;
    private:
    int f(int i,int j,bool isTrue,string &s,vector<vector<vector<int>>>&dp){
        if(i>j)    return 0;
        if(i==j){
            if(isTrue)  return s[i]=='T';
            return s[i]=='F';
        }
        if(dp[i][j][isTrue]!=-1)    return dp[i][j][isTrue];
        int cnt=0;
        for(int ind=i+1;ind<=j-1;ind+=2){
            int lt=f(i,ind-1,1,s,dp);
            int lf=f(i,ind-1,0,s,dp);
            int rt=f(ind+1,j,1,s,dp);
            int rf=f(ind+1,j,0,s,dp);
            if(s[ind]=='&'){
                if(isTrue)
                    cnt=(cnt+(lt*rt)%mod)%mod;
                else    cnt=(cnt+(lt*rf)%mod+(lf*rt)%mod+(lf*rf)%mod)%mod;
            }
            else if(s[ind]=='|')  {
                if(isTrue)  cnt=(cnt+(lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
                else    cnt=(cnt+(lf*rf)%mod)%mod;
            }
            else {
                if(isTrue)  cnt=(cnt+(lt*rf)%mod+(lf*rt)%mod)%mod;
                else    cnt=(cnt+(lt*rt)%mod+(lf*rf)%mod)%mod;
            }
        }
        return dp[i][j][isTrue]=cnt; 
    }
public:
    int countWays(int N, string s){
        // code here
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return f(0,N-1,1,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends