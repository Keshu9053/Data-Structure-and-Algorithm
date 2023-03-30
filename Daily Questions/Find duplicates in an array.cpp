class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      vector<int>ans;
      int n = nums.size()+1;
      for(int i=0;i<nums.size();++i){
          int index = (nums[i]-1)%n;       // %n for Tracking the index.................
          nums[index] += n;                // +n hum isliye kr re hai taki ye pata laaga sake ki konsa element repeat ho raha hai 
      }
      for(int i=0;i<n-1;++i){
          if(nums[i]/n >= 2) ans.push_back(i+1);       
      }

      return ans;
    }
};
