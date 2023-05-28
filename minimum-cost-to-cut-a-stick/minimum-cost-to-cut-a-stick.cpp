class Solution {
public:
    int f(int i , int j , vector<int>&cuts , vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int ind = i ; ind<=j ; ++ind){
            int cost = cuts[j+1] - cuts[i-1] + f(i , ind-1 , cuts ,dp) + 
                                                    f(ind+1 , j , cuts,dp);
            mini = min(mini , cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin() , 0);
        cuts.push_back(n);
        sort(cuts.begin() , cuts.end()); 
        int s = cuts.size();
        vector<vector<int>>dp(s+1 , vector<int>(s+1 , -1));
        return f(1 , cuts.size()-2 , cuts ,dp);
    }
};