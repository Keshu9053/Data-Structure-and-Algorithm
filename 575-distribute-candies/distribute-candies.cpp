class Solution {
public:
    int distributeCandies(vector<int>& arr) {
        int count = 0;
        set<int>s(arr.begin(),arr.end());
        int n = s.size();
        int eat = arr.size()/2;
        if(n < eat) return n;
        return eat;

    }
};