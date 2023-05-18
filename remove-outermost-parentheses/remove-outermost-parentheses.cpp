class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<int> st;
        for(int i=0;i<s.size();++i){
            if(s[i] == '('){
                if(!st.empty()) ans+=s[i];
                st.push(s[i]);
            }
            else{
                st.pop();
                if(!st.empty()) ans+=s[i];
            }
        }
            return ans;
       
    }
};