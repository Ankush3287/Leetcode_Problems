class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int n=a.size();
        vector<int>ans;
        if(n%2==1){
            return ans;
        }
        sort(a.begin(),a.end());
        map<int,int>m;
        for(auto it:a)  m[it]++;
        for(auto it:a){
            if(m[it]==0)    continue;
            if(m[it*2]==0)  return {};
            ans.push_back(it);
            m[it]--;
            m[it*2]--;
        }
        return ans;
    }
};