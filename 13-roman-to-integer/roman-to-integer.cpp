class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp['I'] = 1; mp['V'] = 5; mp['X'] = 10; mp['L'] = 50; mp['C'] = 100;
        mp['D'] = 500; mp['M'] = 1000;
        stack<char>st;
        for(int i=0;i<s.size();++i) st.push(s[i]);
        int n  = mp[st.top()];
        cout<<n;
        st.pop();
        int ans = n;
        while(!st.empty()){
            int t = mp[st.top()];
            st.pop();
            if(t<n) ans-= t;
            else ans+=t;
            n = t;
        }
        return ans;
    }
};
