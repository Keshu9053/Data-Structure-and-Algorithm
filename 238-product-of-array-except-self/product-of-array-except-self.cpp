class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
       vector<int>left;
       vector<int>right(n,0);
       vector<int>ans(n,0);
       int product = 1;
       

       for(int i = 0; i<n;++i) {
           product *= nums[i];
           left.push_back(product);
           
       }
       product = 1;

       for(int j = n-1;j>=0;--j) {
           product *= nums[j];
           right[j] = product;
    
       }
        ans[0] = right[1];
        ans[n-1] = left[n-1-1];
        for(int i = 1;i<n-1;++i) {
            ans[i] = left[i-1]*right[i+1];
        }
        return ans;
    }

};