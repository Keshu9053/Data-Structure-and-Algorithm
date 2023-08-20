class Solution {
public:
    int mySqrt(int x) {
        if( x == 0) return 0;

        int low = 1;
        int high = x;
        int ans = 1;

        while(low<=high) {
          int mid = low + (high - low)/2;
          if(x/mid == mid) return mid;
          if(x/mid > mid) {
            ans = mid;
            low = mid+1;
          }
          else high = mid - 1;
        }
      return ans;
    }
};