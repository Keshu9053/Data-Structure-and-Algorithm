class Solution {
public:
    int f(int len_of_string , int low , int high , int one , int zero, vector<int>&dp) {
        if(len_of_string > high) return 0;
        int res = 0;
        if(dp[len_of_string] != -1) return dp[len_of_string];
        if(len_of_string >= low && len_of_string <= high) res = 1;
        res += f(len_of_string + one , low , high , one , zero,dp)%1000000007;
        res = ((res %1000000007) + f(len_of_string + zero , low , high , one , zero,dp)%1000000007)
                %1000000007;
        return dp[len_of_string] = res;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1 , -1);
        return f(0,low,high,zero,one,dp);
    }
};