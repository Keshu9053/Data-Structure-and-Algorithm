class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        set<int>st;
        int count = 0;
        int ans = 0;
        int n = arr.size();

        for(int i = 0;i<n;++i) {
            st.insert(arr[i]);
        }

        for(auto i: st) {
            if( st.find(i+1) == st.end()) {
                count = 1;
                while(st.find(i-1) != st.end()) {
                    count++;
                    i = i-1;
                }
                ans = max(ans,count);
            }
        }

        return ans;
    }
};