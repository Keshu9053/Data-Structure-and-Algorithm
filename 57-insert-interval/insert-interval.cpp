class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();

        for(int i = 0; i<n ;++i) {
            if(ans.empty() || ans.back()[1] < intervals[i][0]) 
                ans.push_back(intervals[i]);
            else ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        }

        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new1) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int j = 0;   
        for(int i = n-1;i>=0; --i) {
            if(intervals[i][0] < new1[0]) {
                j = i+1;
                break;
            }
        }
        intervals.push_back(new1);
        for(int i = n;i>j;--i) {
            swap(intervals[i],intervals[i-1]);
        } 

    

        return merge(intervals);
        
    }
};