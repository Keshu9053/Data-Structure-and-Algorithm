class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        cout<<n;
        vector<int>ans;
        long long int sum = 0;

        if(2*k<n) {
            for(int i = 0;i<2*k+1;++i) {
                sum += nums[i];
            }
            for(int i = 0;i<k;++i) {
                ans.push_back(-1);
            }

            int i = 0;
            int j = 2*k+1;
          
            while(j<n) {
                ans.push_back(sum/(2*k+1));
                sum += nums[j] - nums[i];
                i++;
                j++;
            }
            ans.push_back(sum/(2*k+1));
        }
         while(ans.size() < n) {
            ans.push_back(-1);
        }
        return ans;
    }
};