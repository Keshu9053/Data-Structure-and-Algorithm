class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int t = 0;
        int f = 0;
        int ans = 0;
        while(j<n) {
            if(s[j] == 'T') t++;
            else f++;
            while(t>k && f>k) {
                if(s[i] == 'T') t--;
                else f--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};