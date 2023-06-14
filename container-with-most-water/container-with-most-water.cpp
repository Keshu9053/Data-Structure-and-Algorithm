class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int i = 0;
        int j = n-1;

        while(i<j) {
            int mn = min(height[i],height[j]);
            int val = mn*(j-i);
            ans = max(ans,val);
            if(height[i] == mn) i++;
            else j--;
        }

        return ans;  
    }
};