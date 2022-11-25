//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
	
public:
vector<int>parent,rank,size;
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
    bool isValid(int nr,int nc,int n){
        return (nr>=0 && nc>=0 && nr<n && nc<n);
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)   continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int k=0;k<4;k++){
                    int nr=dr[k]+i;
                    int nc=dc[k]+j;
                    if(isValid(nr,nc,n) && grid[nr][nc]==1){
                        int node=i*n+j;
                        int adj=nr*n+nc;
                        ds.unionBySize(node,adj);
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)   continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int>st;
                for(int k=0;k<4;k++){
                    int nr=dr[k]+i;
                    int nc=dc[k]+j;
                    if(isValid(nr,nc,n) && grid[nr][nc]==1){
                        st.insert(ds.findUlParent(nr*n+nc));   
                    }
                }
                int cnt=1;
                for(auto it:st){
                    cnt+=ds.size[it];
                }
                mx=max(mx,cnt);
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findUlParent(i)]);
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends