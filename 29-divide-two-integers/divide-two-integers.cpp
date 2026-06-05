class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        bool sign = true;
        if (dividend >= 0 && divisor < 0)
            sign = false;
        if (dividend <= 0 && divisor > 0)
            sign = false;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long quo = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quo += (1 << cnt);
            n = n - (d << cnt);
        }
        if(quo == (1<<31) && sign) return INT_MAX;
        if(quo == (1<<31) && !sign) return INT_MIN;

        return sign ? quo : -quo;
    }
};