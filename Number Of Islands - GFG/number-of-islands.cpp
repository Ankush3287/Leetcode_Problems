//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
	vector<int>parent,rank,size;
public:
	DisjointSet(int n){
		rank.resize(n+1,0);
		size.resize(n+1,0);
		parent.resize(n+1,0);
		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
		for(int i=0;i<=n;i++){
			size[i]=1;
		}
	}
	int findUlParent(int node){
		if(node==parent[node])	return node;
		return parent[node]=findUlParent(parent[node]);
	}	
	void unionByRank(int u,int v){
		int ulp_u=findUlParent(u);
		int ulp_v=findUlParent(v);
		if(ulp_u==ulp_v)	return;
		if(rank[ulp_u]<rank[ulp_v]){
			parent[ulp_u]=ulp_v;
		}
		else if(rank[ulp_v]<rank[ulp_u]){
			parent[ulp_v]=ulp_u;
		}
		else{
			parent[ulp_v]=ulp_u;
			rank[ulp_u]++;
		}
	}
	void unionBySize(int u,int v){
		int ulp_u=findUlParent(u);
		int ulp_v=findUlParent(v);
		if(ulp_u==ulp_v)	return;
		if(size[ulp_u]<size[ulp_v]){
			parent[ulp_u]=ulp_v;
			size[ulp_v]+=size[ulp_u];
		}
		else{
			parent[ulp_v]=ulp_u;
			size[ulp_u]+=size[ulp_v];
		}
	}
};
class Solution {
    private:
    bool isValid(int nr,int nc,int n,int m){
        return (nr>=0 && nc>=0 && nr<n && nc<m);
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int>ans;
        for(auto it:operators){
            int r=it[0];
            int c=it[1];
            if(vis[r][c]==1)  {
                ans.push_back(cnt);
                continue;
            }
            vis[r][c]=1;
            cnt++;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(isValid(nr,nc,n,m)){
                    int node=m*r+c;
                    int adj=m*nr+nc;
                    if(vis[nr][nc]==1){
                        if(ds.findUlParent(node)!=ds.findUlParent(adj)){
                            cnt--;
                            ds.unionBySize(node,adj);
                        }
                        // cnt--;
                        // ds.unionBySize(node,adj);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends