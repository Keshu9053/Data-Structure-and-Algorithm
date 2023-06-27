class Solution {
public:
    double solve(double x,long long n,double ans){
        if(n == 0) return 1;
        if(n == 1) return x;
        
        if(n%2 == 0) {
            x = x*x;
            ans = solve(x,n/2,ans);
            return ans;
        }
        else {
            double a = x;
            ans = solve(x,n-1,ans);
            return ans*a;
        }
    }
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double ans = 1.0;
        long long nn = n;

        if(n<0) {
            nn = -1*nn;
        }
        ans = solve(x,nn,ans);
        if(n<0) {
            ans = (double)1.0/ans;
        }
        return ans;
    }
};