class Solution {
public:
    void merge(int low, int mid, int high, int& reverse_pairs, vector<int>& nums) {
        
        int j = mid+1;
        for(int i = low ; i<mid+1 ; i++) {
            while( j<=high && nums[i] > 2*(long long)nums[j] ) 
                j++;
            reverse_pairs += j-(mid+1);
        }
        
        int i = low;
        j = mid+1;
        int k = 0;

        vector<int>temp;
        while( i<=mid && j<=high) {
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while( i<= mid ) {
            temp.push_back(nums[i]);
            i++;
        }

        while( j<=high ) {
            temp.push_back(nums[j]);
            j++;
        }

        int n = temp.size();
        for(int i = 0; i<n; ++i) {
            nums[low++] = temp[i];
        }
    }

    void mergeSort(int low, int high, int& reverse_pairs, vector<int>& nums) {
        if(low >= high) return;
        int mid = (low+high)/2;
        mergeSort(low, mid, reverse_pairs, nums);
        mergeSort(mid+1, high, reverse_pairs, nums);
        merge(low, mid, high, reverse_pairs, nums);
    }

    int reversePairs(vector<int>& nums) {
        int reverse_pairs = 0;
        int length = nums.size();
        mergeSort(0,length-1,reverse_pairs,nums);
        return reverse_pairs;
    }
};