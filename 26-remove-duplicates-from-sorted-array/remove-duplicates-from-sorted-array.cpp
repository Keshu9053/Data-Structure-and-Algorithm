class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int k = 0;
        for(int i = 1;i<arr.size();++i) {
            if(arr[i] != arr[k]) arr[++k] = arr[i];
        }
        return k+1;
    }
};