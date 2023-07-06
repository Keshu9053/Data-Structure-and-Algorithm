class Solution {
public:
    int minSubArrayLen(int k , vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int n = nums.size();
        int sum = 0;

        while(j<n) {

            sum += nums[j];
            if(sum>=k) {
                while(sum>=k) {
                    ans = min(ans,j-i+1);
                    sum -= nums[i];
                    i++;
                }
            }
            j++;
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};