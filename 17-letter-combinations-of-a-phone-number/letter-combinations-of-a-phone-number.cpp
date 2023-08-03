class Solution {
public:
    void solve(int i, string digits, string& output, vector<string>&ans, string map[]) {
        if(i >= digits.size()) {
            ans.push_back(output);
            return;
        }
        int num = digits[i] - '0';
        string str = map[num];
        for(int j = 0;j<str.size();++j) {
            output.push_back(str[j]);
            solve(i+1,digits,output,ans,map);
            output.pop_back();
            
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output;
        if(digits.size() == 0) return ans;
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,output,ans,map);
        return ans;
    }
};

// 2: abc 3: def