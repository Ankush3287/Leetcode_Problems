//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int>prev(W+1);
        for(int i=0;i<=W;i++){
            prev[i]=val[0]*(i/wt[0]);
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int pick=0;
                int notPick=prev[j];
                if(wt[i]<=j)  pick=val[i]+prev[j-wt[i]];
                prev[j]=max(pick,notPick);
            }
           
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