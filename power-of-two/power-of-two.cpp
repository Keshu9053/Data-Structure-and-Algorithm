class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1 || n==0) return n;
        while(n%2 == 0) {
            n = n/2;
            if(n==1) return true;
        }
        return false;
    }
};