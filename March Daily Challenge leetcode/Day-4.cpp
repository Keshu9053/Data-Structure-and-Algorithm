
class Solution {
public:
    int partitionString(string s) {
        int cnt = 0;
        unordered_set<char>st;
        int i = 0;
        while(i<s.size())
        {
            st.clear();
            while(i<s.size() && st.find(s[i]) == st.end())
            {
                st.insert(s[i]);
                i++;
            }
            cnt++;
        }
        return cnt;
    }
};
