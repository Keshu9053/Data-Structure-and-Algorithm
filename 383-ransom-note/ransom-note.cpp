class Solution {
public:
    bool canConstruct(string r, string magazine) {
        map<char,int>mp;
        int n = magazine.size();
        int m = r.size();
        if(n<m) return false;
        for(int i = 0;i<n;++i) mp[magazine[i]]++;
        for(int i = 0;i<r.size();++i) {
            if(mp.find(r[i]) == mp.end() || mp[r[i]] == 0){
                return false;
            }
            if(mp.find(r[i]) != mp.end()) mp[r[i]]--;
        }
        return true;
    }
};