class Solution {
public:
    int trap(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int mxl[n];
        int mxr[n];
        mxl[0] = heights[0];
        for(int i=1;i<n;++i){
            mxl[i] = max(mxl[i-1] , heights[i]);
        }
        mxr[n-1] = heights[n-1];
        for(int i = n-2 ; i>=0 ; --i)
            mxr[i] = max(mxr[i+1] , heights[i]);
        for(int i=0;i<n;++i){
            int mn = min(mxl[i], mxr[i]);
            ans += mn - heights[i]; 
        }
        return ans;
    }
};