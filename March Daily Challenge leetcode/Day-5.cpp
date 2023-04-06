class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = nums[0];
        long long mini = nums[0];
        for(int i = 1 ;i<nums.size();++i)
        {
            sum += nums[i];
            if(nums[i] >= mini){
                int avg = sum/(i+1);
                if(avg >= mini){
                    if(sum%(i+1)) mini = avg+1;
                    else mini = avg;
                }
            }
        }
        
        return mini;
    }
};
