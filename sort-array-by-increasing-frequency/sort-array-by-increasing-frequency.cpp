class Solution {
public:
    static bool cmp(pair<int,int> a , pair<int,int> b){
        if(a.second != b.second) return a.second<b.second;
        else return a.first>b.first;
    }
    vector<int> frequencySort(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        
        map<int,int>mp;
        for(int i=0;i<n;++i)
            mp[arr[i]]++;
        vector<pair<int,int>>m;
        for(auto i:mp){
            int freq = i.second;
            int ele = i.first;
            m.push_back({ele,freq});
        }
        sort(m.begin(),m.end(),cmp);
        for(auto i:m){
            int freq = i.second;
            int ele = i.first;
            for(int i=0;i<freq;++i) ans.push_back(ele);
        }
        return ans;
    }
};