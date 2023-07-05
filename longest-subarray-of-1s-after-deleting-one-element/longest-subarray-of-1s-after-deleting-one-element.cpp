class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int count = 0;
        int n = nums.size();
        int mx = 0;
        int count0 = 0;

        while(j<n) 
        {   
            if(nums[j] == 0) count0++;
            count++;

            if(count0<=1) {
                mx = max(mx,j-i);
            }
            else {
                while(count0 > 1) 
                {
                    if(nums[i] == 0) count0--;
                    i++;
                }
            }
            j++;
        }
        return mx;
    }
};