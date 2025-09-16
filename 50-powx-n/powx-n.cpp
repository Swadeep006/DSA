class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N == 0) {
            return 1;
        } else if (N == 1) {
            return x;
        } else if (N < 0) {
            N = -N;
            x = 1 / x;
            return ((N&1)==0)?myPow(x,N/2)*myPow(x,N/2):myPow(x,N/2)*myPow(x,N/2)*x;
        } else {
            double half = myPow(x, N / 2);
            if ((N & 1) == 0) {
                return half * half;
            } else {
                return half * half * x;
            }
        }
    }
};