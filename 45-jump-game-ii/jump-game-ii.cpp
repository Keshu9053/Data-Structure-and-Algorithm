class Solution {
public:
    int jump(vector<int>& nums) {
        // if(nums[0] == 0) return 0; 
        int jump = 0;
        int des = 0;
        int pos = 0;
       
        for(int i = 0;i<nums.size()-1;++i) {
            des = max(des,nums[i]+i);
            if(i == pos) {
                jump++;
                pos = des;
            }
        }
        return jump;
    }
};