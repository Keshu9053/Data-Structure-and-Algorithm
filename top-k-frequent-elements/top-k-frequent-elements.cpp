class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
    vector<int>ans;
        map<int,int>mp;
        int n = arr.size();
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>minh;
        for(int i=0;i<n;++i) mp[arr[i]]++;
        for(auto it:mp){
            minh.push({it.second,it.first});
            if(minh.size()>k) minh.pop();
        }
        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};