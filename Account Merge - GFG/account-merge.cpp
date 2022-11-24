//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

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
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(m.find(mail)==m.end())   m[mail]=i;
                else    ds.unionBySize(i,m[mail]);
            }
        }
        vector<string> mergedMail[n];
        for(auto it:m){
            string mail=it.first;
            int node=ds.findUlParent(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            vector<string>temp;
            if(mergedMail[i].size()==0) continue;
            temp.push_back(accounts[i][0]);
            sort(mergedMail[i].begin(),mergedMail[i].end());
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends