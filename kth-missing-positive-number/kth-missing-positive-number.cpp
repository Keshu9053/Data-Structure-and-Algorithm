class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size()-1;
        int val = arr[n];
        int i = 0;
        int j = 1;
        while(j != val) {
            if(arr[i] == j){
                i++;    
                // break;
            } 
            else {
                k--;
                if(k == 0) return j;
            }
            j++;
        }
        return val+k;
    }
};