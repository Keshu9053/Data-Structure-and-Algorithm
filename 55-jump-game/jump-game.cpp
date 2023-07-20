class Solution {
public:
    bool canJump(vector<int>& nums) {
        int momentum = nums[0];
        int n = nums.size();
        for(int i = 0;i<n;++i) {
            momentum--;
            momentum = max(nums[i],momentum);
            if(momentum == 0 && i != nums.size()-1) return false;
        }
        return true;
    }
};