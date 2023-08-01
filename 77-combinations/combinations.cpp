class Solution {
public:
    void solve(int i, int n,int k,vector<int>& ans,vector<vector<int>>& res) {
        if(i == n+1) {
            if(ans.size() == k) res.push_back(ans);
            return; 
        }
        ans.push_back(i);
        solve(i+1,n,k,ans,res);
        ans.pop_back();
        solve(i+1,n,k,ans,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        vector<vector<int>>res;
        solve(1,n,k,ans,res);
        return res;
    }
};