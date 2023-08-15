class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int ans = 0;
        sort(cost.begin(),cost.end());
        int i = n-1;
        while(i>=0) {
            int a = cost[i];
            int b = 0;
            if(i-1 >=0) b = cost[i-1];
            ans += (a+b);
            i = i-3;
        }
        return ans;
    }
};