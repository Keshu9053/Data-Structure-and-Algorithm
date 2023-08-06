class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>m;
        int n = nums.size();
        for(int i = 0; i<n ; ++i) {
            if(m.find(target - nums[i]) != m.end()) {
                ans.push_back(m[target - nums[i]] +1);
                ans.push_back(i+1);
                return ans;
            }
            else {
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};