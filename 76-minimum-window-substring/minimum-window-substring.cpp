class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int count = t.size();
        int i = 0;
        int j = 0;
        map<int,int>mp;
        int mn = INT_MAX;
        int startOfString = 0;
        for(int k = 0; k<count;++k) {
            mp[t[k]]++;
        }

        while (j < n) {
            if(mp[s[j++]]-- > 0) {
                count--; 
            }
            
            while(count == 0) {
                if(j-i < mn) {
                    mn = j-i;
                    startOfString = i;
                }
                if(mp[s[i++]]++ == 0) {
                    count++;
                }
                
            }
            
        }
        return mn == INT_MAX ? "" : s.substr(startOfString , mn);
    }
};