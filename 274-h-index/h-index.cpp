class Solution {
public:
    int hIndex(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int>freq(n+1);

        for(int i = 0; i < n; ++i) {
            if(nums[i] > n-1) freq[n]++;
            else freq[nums[i]]++;
        }
        int sum = 0;
        for(int i = n;i>=0;--i) {
            sum += freq[i];
            if(sum >= i) return i;
        }
        return ans;
    }
};