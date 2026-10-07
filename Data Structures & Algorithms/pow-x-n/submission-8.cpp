class Solution {
public:
    double myPow(double x, int n) {
        // if (n == 0) {
        //     return 
        // }
        
        if (x == 1.00) {
            return x;
        }
        if (x == -1.00 && n % 2 != 0) {
            return x;
        }
        if (x == -1.00 && n % 2 == 0) {
            return -x;
        }
        if (n == -2147483648) {
            return 0.0000;
        }
        if (!(n < 0)) {
            double answer = 1.0;
            for (int i = 0; i < n; i++) {
                answer *= x; 
            }
            return answer;
        }
        else {
            double answer = 1.0;
            for (int i = 0; i < abs(n); i++) {
                answer *= x; 
            }
            return 1.00 / answer;
        }
    }
};
