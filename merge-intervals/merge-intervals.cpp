
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int n = intervals.size();

        for(int i=0;i<n;++i) {
            if(ans.empty() || ans.back()[1] < intervals[i][0]) 
                ans.push_back(intervals[i]);
            else{
                if(ans.back()[1] >= intervals[i][0])
                    ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
        }
        
        return ans;
    }
};



    // O{NlogN} + O(2n)
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(),intervals.end());
    //     vector<vector<int>>ans;
    //     int n = intervals.size();

    //     for(int i=0;i<n;++i) {
    //         int start = intervals[i][0];
    //         int end = intervals[i][1];
    //         if(!ans.empty() && end <= ans.back()[1] ) continue;
    //         for(int j = i+1; j<n;++j) {
    //             if(intervals[j][0] <= end) {
    //                 end = max(end,intervals[j][1]);
    //             }
    //             else break;
    //         }
    //         ans.push_back({start,end});
    //     }
        
    //     return ans;
    // }